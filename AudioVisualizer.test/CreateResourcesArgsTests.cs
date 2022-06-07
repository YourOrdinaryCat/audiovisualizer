﻿using Microsoft.VisualStudio.TestTools.UnitTesting;
using System;

namespace AudioVisualizer.test
{
    [TestClass]
    public class CreateResourcesArgsTests
    {
        AudioVisualizer.CreateResourcesEventArgs sut;
        Object fakeCreator = new Object();

        [TestInitialize]
        public void TestInit()
        {
            sut = new CreateResourcesEventArgs(CreateResourcesReason.New, fakeCreator);
        }

        [TestMethod]
        [TestCategory("CreateResourcesEventArgs")]
        public void CreateResourcesEventArgs_IsReasonNew()
        {
            Assert.AreEqual(CreateResourcesReason.New, sut.Reason);
        }
        [TestMethod]
        [TestCategory("CreateResourcesEventArgs")]
        public void CreateResourcesEventArgs_IsCreatorObjectCorrect()
        {
            Assert.AreEqual(fakeCreator, sut.ResourceCreator);
        }
    }
}
