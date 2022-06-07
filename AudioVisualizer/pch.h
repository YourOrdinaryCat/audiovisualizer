//
// pch.h
// Header for platform projection include files
//

#pragma once

#define NOMINMAX
#ifdef _DEBUG
#define _TRACE_
#endif

#include <Unknwn.h>


// WinRT
#include <winrt/base.h>

#include <winrt/Windows.ApplicationModel.h>

#include <winrt/Windows.Foundation.h>
#include <winrt/Windows.Foundation.Collections.h>
#include <winrt/Windows.Foundation.Diagnostics.h>
#include <winrt/Windows.Foundation.Numerics.h>

#include <winrt/Windows.Media.h>
#include <winrt/Windows.Media.Audio.h>
#include <winrt/Windows.Media.MediaProperties.h>

#include <winrt/Windows.System.Threading.h>

#include <winrt/Windows.UI.h>
#include <winrt/Windows.UI.Core.h>
#include <winrt/Windows.UI.Composition.h>

#include <winrt/Windows.UI.Xaml.h>
#include <winrt/Windows.UI.Xaml.Hosting.h>
#include <winrt/Windows.UI.Xaml.Media.h>


// Interop
#include <Windows.Media.h>

#include <Windows.Media.Audio.h>
#include <Windows.Media.Core.h>

#include <Windows.Media.Core.Interop.h>
#include <Windows.Media.MediaProperties.h>


// Media Foundation
#include <mfapi.h>
#include <mferror.h>
#include <mfidl.h>
#include <mfreadwrite.h>
#include <mftransform.h>

// Math
#include <AudioMath.h>
#include <DirectXMath.h>

// Other
#include <memorybuffer.h>
#include <util.h>
#include <XDSP.h>
