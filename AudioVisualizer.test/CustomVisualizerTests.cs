using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace AudioVisualizer.test
{
    [TestClass]
    public class CustomVisualizerTests
    {
        CustomVisualizer sut;

        [TestInitialize]
        public void TestInit()
        {
            sut = new AudioVisualizer.CustomVisualizer();
        }

    }
}
