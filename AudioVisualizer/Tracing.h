#pragma once

#include "VisualizationDataFrame.h"


#ifdef _TRACE_

class Trace
{
private:
	static void AddMediaTypeFields(IMFMediaType* pType, winrt::Windows::Foundation::Diagnostics::LoggingFields& fields);
	static void AddSampleFields(IMFSample* pSample, winrt::Windows::Foundation::Diagnostics::LoggingFields& fields);
public:
	struct Activity {
	private:
		winrt::Windows::Foundation::Diagnostics::LoggingActivity _activity;
	public:
		Activity(winrt::Windows::Foundation::Diagnostics::LoggingActivity const& activity) : _activity(activity) {}
		~Activity() {
			_activity.StopActivity(_activity.Name());
		}
	};
	static void Initialize();
	static void ShutDown();
	static Activity  Constructor(LPCTSTR szObjectName, void* pObject);
	static void MediaAnalyzer_SetInputType(IMFMediaType* pType, bool bTest);
	static void MediaAnalyzer_SetOutputType(IMFMediaType* pType, bool bTest);
	static void MediaAnalyzer_ProcessMessage(MFT_MESSAGE_TYPE message);
	static void MediaAnalyzer_ProcessInput(IMFSample* pSample);
	static void MediaAnalyzer_ProcessOutput();
	static void MediaAnalyzer_AnalyzerOutput(winrt::AudioVisualizer::VisualizationDataFrame frame);
	static void MediaAnalyzer_GetFrame(winrt::Windows::Foundation::IReference<winrt::Windows::Foundation::TimeSpan> time, winrt::AudioVisualizer::VisualizationDataFrame const& frame);
	static void MediaAnalyzer_OutputQueueAdd(winrt::AudioVisualizer::VisualizationDataFrame const& frame, winrt::AudioVisualizer::VisualizationDataFrame const& front, winrt::AudioVisualizer::VisualizationDataFrame const& back, size_t queueSize);
	static void MediaAnalyzer_OutputQueueRemove(winrt::AudioVisualizer::VisualizationDataFrame const& frame, size_t queueSize);
	static void MediaAnalyzer_OutputQueueGet(winrt::Windows::Foundation::TimeSpan time, winrt::AudioVisualizer::VisualizationDataFrame const& front, winrt::AudioVisualizer::VisualizationDataFrame const& back, size_t queueSize);
	static void MediaAnalyzer_OutputQueueBehind(winrt::Windows::Foundation::TimeSpan time);
	static void MediaAnalyzer_OutputQueueItemFound(winrt::Windows::Foundation::TimeSpan time);
	static void MediaAnalyzer_OutputQueueTest(winrt::Windows::Foundation::TimeSpan queueItem, winrt::Windows::Foundation::TimeSpan time, bool isQueueItemBefore, bool isQueueItemAfter);
	static void MediaAnalyzer_OutputQueueClear();

	static void AudioAnalyzer_ProcessInput(winrt::Windows::Media::AudioFrame const& frame);
	static void AudioAnalyzer_RunAsync();
	static winrt::Windows::Foundation::Diagnostics::LoggingActivity AudioAnalyzer_Calculate();
	static void AudioAnalyzer_SeedFromPosition(int64_t position);
	static void AudioAnalyzer_SeedFromStream(winrt::Windows::Foundation::IReference<winrt::Windows::Foundation::TimeSpan> const& time, int64_t position);

	static void VisualizeControl_RecreateDevice(winrt::hresult_error const& err);
	static void VisualizeControl_DrawLoopException(winrt::hresult_error const& err);
	static winrt::Windows::Foundation::Diagnostics::LoggingActivity VisualizeControl_StartDraw(winrt::AudioVisualizer::VisualizationDataFrame const& frame, winrt::Windows::Foundation::IReference<winrt::Windows::Foundation::TimeSpan> const& time);

	static void VisualizerAudioEffect_ProcessFrame(winrt::Windows::Media::AudioFrame const& frame);
	static void VisualizerAudioEffect_OnAnalyzerOutput(winrt::AudioVisualizer::VisualizationDataFrame const& frame);
	static void VisualizerAudioEffect_GetData(winrt::AudioVisualizer::VisualizationDataFrame const& frame);
	static void VisualizerAudioEffect_DiscardQueuedFrames();

	static void SourceConverter_SourceConfigurationChanged(winrt::Windows::Foundation::IInspectable const& sender, winrt::hstring const& propertyName, winrt::Windows::Foundation::IInspectable const& self);

	static void PlaybackSource_CreateFromMediaPlayer();
	static void PlaybackSource_SourcePropertyChanged(winrt::Windows::Foundation::IInspectable const& sourceObject);
	static winrt::Windows::Foundation::Diagnostics::LoggingActivity AudioAnalyzer_Lifetime_Start(LPCTSTR className);
	static void AudioAnalyzer_Lifetime_Stop(winrt::Windows::Foundation::Diagnostics::LoggingActivity activity);
};

namespace lifetime_tracker_impl
{
	static std::map<std::wstring, long> _objectCounter;
};

template<typename T>
struct lifetime_tracker
{
private:
	winrt::Windows::Foundation::Diagnostics::LoggingActivity _activity{ nullptr };
public:
	lifetime_tracker()
	{
		long objectCount = lifetime_tracker_impl::_objectCounter[winrt::name_of<T>().data()]++;
		_activity = Trace::AudioAnalyzer_Lifetime_Start(winrt::name_of<T>().data());
	}
	virtual ~lifetime_tracker()
	{
		long count = --lifetime_tracker_impl::_objectCounter[winrt::name_of<T>().data()];
		assert(count >= 0);
		Trace::AudioAnalyzer_Lifetime_Stop(_activity);
	}
};
#else

template<typename T>
struct lifetime_tracker
{};

#endif