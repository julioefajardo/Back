
"use strict";

let simRosGetDialogInput = require('./simRosGetDialogInput.js')
let simRosSynchronous = require('./simRosSynchronous.js')
let simRosGetIntegerParameter = require('./simRosGetIntegerParameter.js')
let simRosGetStringParameter = require('./simRosGetStringParameter.js')
let simRosReadVisionSensor = require('./simRosReadVisionSensor.js')
let simRosGetObjectIntParameter = require('./simRosGetObjectIntParameter.js')
let simRosGetUIButtonProperty = require('./simRosGetUIButtonProperty.js')
let simRosSetSphericalJointMatrix = require('./simRosSetSphericalJointMatrix.js')
let simRosStopSimulation = require('./simRosStopSimulation.js')
let simRosSetJointPosition = require('./simRosSetJointPosition.js')
let simRosEraseFile = require('./simRosEraseFile.js')
let simRosRemoveUI = require('./simRosRemoveUI.js')
let simRosSetIntegerSignal = require('./simRosSetIntegerSignal.js')
let simRosStartSimulation = require('./simRosStartSimulation.js')
let simRosGetAndClearStringSignal = require('./simRosGetAndClearStringSignal.js')
let simRosAuxiliaryConsoleClose = require('./simRosAuxiliaryConsoleClose.js')
let simRosGetFloatSignal = require('./simRosGetFloatSignal.js')
let simRosAppendStringSignal = require('./simRosAppendStringSignal.js')
let simRosSetBooleanParameter = require('./simRosSetBooleanParameter.js')
let simRosSetUIButtonProperty = require('./simRosSetUIButtonProperty.js')
let simRosSetObjectPosition = require('./simRosSetObjectPosition.js')
let simRosGetInfo = require('./simRosGetInfo.js')
let simRosCreateDummy = require('./simRosCreateDummy.js')
let simRosSetVisionSensorImage = require('./simRosSetVisionSensorImage.js')
let simRosGetVisionSensorImage = require('./simRosGetVisionSensorImage.js')
let simRosReadForceSensor = require('./simRosReadForceSensor.js')
let simRosSetStringSignal = require('./simRosSetStringSignal.js')
let simRosReadCollision = require('./simRosReadCollision.js')
let simRosSetJointTargetVelocity = require('./simRosSetJointTargetVelocity.js')
let simRosSynchronousTrigger = require('./simRosSynchronousTrigger.js')
let simRosEnableSubscriber = require('./simRosEnableSubscriber.js')
let simRosGetDialogResult = require('./simRosGetDialogResult.js')
let simRosAuxiliaryConsolePrint = require('./simRosAuxiliaryConsolePrint.js')
let simRosAuxiliaryConsoleShow = require('./simRosAuxiliaryConsoleShow.js')
let simRosClearStringSignal = require('./simRosClearStringSignal.js')
let simRosLoadScene = require('./simRosLoadScene.js')
let simRosGetObjectHandle = require('./simRosGetObjectHandle.js')
let simRosGetCollisionHandle = require('./simRosGetCollisionHandle.js')
let simRosDisableSubscriber = require('./simRosDisableSubscriber.js')
let simRosSetObjectSelection = require('./simRosSetObjectSelection.js')
let simRosGetJointState = require('./simRosGetJointState.js')
let simRosGetUIHandle = require('./simRosGetUIHandle.js')
let simRosDisablePublisher = require('./simRosDisablePublisher.js')
let simRosGetObjectFloatParameter = require('./simRosGetObjectFloatParameter.js')
let simRosCopyPasteObjects = require('./simRosCopyPasteObjects.js')
let simRosRemoveModel = require('./simRosRemoveModel.js')
let simRosGetModelProperty = require('./simRosGetModelProperty.js')
let simRosSetFloatSignal = require('./simRosSetFloatSignal.js')
let simRosRemoveObject = require('./simRosRemoveObject.js')
let simRosCallScriptFunction = require('./simRosCallScriptFunction.js')
let simRosGetObjectSelection = require('./simRosGetObjectSelection.js')
let simRosSetUIButtonLabel = require('./simRosSetUIButtonLabel.js')
let simRosGetObjectGroupData = require('./simRosGetObjectGroupData.js')
let simRosReadDistance = require('./simRosReadDistance.js')
let simRosPauseSimulation = require('./simRosPauseSimulation.js')
let simRosGetUIEventButton = require('./simRosGetUIEventButton.js')
let simRosGetArrayParameter = require('./simRosGetArrayParameter.js')
let simRosGetObjects = require('./simRosGetObjects.js')
let simRosGetJointMatrix = require('./simRosGetJointMatrix.js')
let simRosLoadUI = require('./simRosLoadUI.js')
let simRosSetObjectFloatParameter = require('./simRosSetObjectFloatParameter.js')
let simRosSetJointForce = require('./simRosSetJointForce.js')
let simRosGetDistanceHandle = require('./simRosGetDistanceHandle.js')
let simRosSetObjectIntParameter = require('./simRosSetObjectIntParameter.js')
let simRosAddStatusbarMessage = require('./simRosAddStatusbarMessage.js')
let simRosSetFloatingParameter = require('./simRosSetFloatingParameter.js')
let simRosGetObjectPose = require('./simRosGetObjectPose.js')
let simRosGetIntegerSignal = require('./simRosGetIntegerSignal.js')
let simRosCloseScene = require('./simRosCloseScene.js')
let simRosGetUISlider = require('./simRosGetUISlider.js')
let simRosDisplayDialog = require('./simRosDisplayDialog.js')
let simRosLoadModel = require('./simRosLoadModel.js')
let simRosAuxiliaryConsoleOpen = require('./simRosAuxiliaryConsoleOpen.js')
let simRosClearIntegerSignal = require('./simRosClearIntegerSignal.js')
let simRosClearFloatSignal = require('./simRosClearFloatSignal.js')
let simRosSetObjectQuaternion = require('./simRosSetObjectQuaternion.js')
let simRosSetArrayParameter = require('./simRosSetArrayParameter.js')
let simRosGetObjectParent = require('./simRosGetObjectParent.js')
let simRosSetJointState = require('./simRosSetJointState.js')
let simRosGetBooleanParameter = require('./simRosGetBooleanParameter.js')
let simRosSetJointTargetPosition = require('./simRosSetJointTargetPosition.js')
let simRosGetFloatingParameter = require('./simRosGetFloatingParameter.js')
let simRosSetObjectParent = require('./simRosSetObjectParent.js')
let simRosGetObjectChild = require('./simRosGetObjectChild.js')
let simRosSetModelProperty = require('./simRosSetModelProperty.js')
let simRosSetUISlider = require('./simRosSetUISlider.js')
let simRosSetObjectPose = require('./simRosSetObjectPose.js')
let simRosEndDialog = require('./simRosEndDialog.js')
let simRosGetCollectionHandle = require('./simRosGetCollectionHandle.js')
let simRosSetIntegerParameter = require('./simRosSetIntegerParameter.js')
let simRosTransferFile = require('./simRosTransferFile.js')
let simRosGetStringSignal = require('./simRosGetStringSignal.js')
let simRosGetVisionSensorDepthBuffer = require('./simRosGetVisionSensorDepthBuffer.js')
let simRosReadProximitySensor = require('./simRosReadProximitySensor.js')
let simRosGetLastErrors = require('./simRosGetLastErrors.js')
let simRosEnablePublisher = require('./simRosEnablePublisher.js')
let simRosBreakForceSensor = require('./simRosBreakForceSensor.js')

module.exports = {
  simRosGetDialogInput: simRosGetDialogInput,
  simRosSynchronous: simRosSynchronous,
  simRosGetIntegerParameter: simRosGetIntegerParameter,
  simRosGetStringParameter: simRosGetStringParameter,
  simRosReadVisionSensor: simRosReadVisionSensor,
  simRosGetObjectIntParameter: simRosGetObjectIntParameter,
  simRosGetUIButtonProperty: simRosGetUIButtonProperty,
  simRosSetSphericalJointMatrix: simRosSetSphericalJointMatrix,
  simRosStopSimulation: simRosStopSimulation,
  simRosSetJointPosition: simRosSetJointPosition,
  simRosEraseFile: simRosEraseFile,
  simRosRemoveUI: simRosRemoveUI,
  simRosSetIntegerSignal: simRosSetIntegerSignal,
  simRosStartSimulation: simRosStartSimulation,
  simRosGetAndClearStringSignal: simRosGetAndClearStringSignal,
  simRosAuxiliaryConsoleClose: simRosAuxiliaryConsoleClose,
  simRosGetFloatSignal: simRosGetFloatSignal,
  simRosAppendStringSignal: simRosAppendStringSignal,
  simRosSetBooleanParameter: simRosSetBooleanParameter,
  simRosSetUIButtonProperty: simRosSetUIButtonProperty,
  simRosSetObjectPosition: simRosSetObjectPosition,
  simRosGetInfo: simRosGetInfo,
  simRosCreateDummy: simRosCreateDummy,
  simRosSetVisionSensorImage: simRosSetVisionSensorImage,
  simRosGetVisionSensorImage: simRosGetVisionSensorImage,
  simRosReadForceSensor: simRosReadForceSensor,
  simRosSetStringSignal: simRosSetStringSignal,
  simRosReadCollision: simRosReadCollision,
  simRosSetJointTargetVelocity: simRosSetJointTargetVelocity,
  simRosSynchronousTrigger: simRosSynchronousTrigger,
  simRosEnableSubscriber: simRosEnableSubscriber,
  simRosGetDialogResult: simRosGetDialogResult,
  simRosAuxiliaryConsolePrint: simRosAuxiliaryConsolePrint,
  simRosAuxiliaryConsoleShow: simRosAuxiliaryConsoleShow,
  simRosClearStringSignal: simRosClearStringSignal,
  simRosLoadScene: simRosLoadScene,
  simRosGetObjectHandle: simRosGetObjectHandle,
  simRosGetCollisionHandle: simRosGetCollisionHandle,
  simRosDisableSubscriber: simRosDisableSubscriber,
  simRosSetObjectSelection: simRosSetObjectSelection,
  simRosGetJointState: simRosGetJointState,
  simRosGetUIHandle: simRosGetUIHandle,
  simRosDisablePublisher: simRosDisablePublisher,
  simRosGetObjectFloatParameter: simRosGetObjectFloatParameter,
  simRosCopyPasteObjects: simRosCopyPasteObjects,
  simRosRemoveModel: simRosRemoveModel,
  simRosGetModelProperty: simRosGetModelProperty,
  simRosSetFloatSignal: simRosSetFloatSignal,
  simRosRemoveObject: simRosRemoveObject,
  simRosCallScriptFunction: simRosCallScriptFunction,
  simRosGetObjectSelection: simRosGetObjectSelection,
  simRosSetUIButtonLabel: simRosSetUIButtonLabel,
  simRosGetObjectGroupData: simRosGetObjectGroupData,
  simRosReadDistance: simRosReadDistance,
  simRosPauseSimulation: simRosPauseSimulation,
  simRosGetUIEventButton: simRosGetUIEventButton,
  simRosGetArrayParameter: simRosGetArrayParameter,
  simRosGetObjects: simRosGetObjects,
  simRosGetJointMatrix: simRosGetJointMatrix,
  simRosLoadUI: simRosLoadUI,
  simRosSetObjectFloatParameter: simRosSetObjectFloatParameter,
  simRosSetJointForce: simRosSetJointForce,
  simRosGetDistanceHandle: simRosGetDistanceHandle,
  simRosSetObjectIntParameter: simRosSetObjectIntParameter,
  simRosAddStatusbarMessage: simRosAddStatusbarMessage,
  simRosSetFloatingParameter: simRosSetFloatingParameter,
  simRosGetObjectPose: simRosGetObjectPose,
  simRosGetIntegerSignal: simRosGetIntegerSignal,
  simRosCloseScene: simRosCloseScene,
  simRosGetUISlider: simRosGetUISlider,
  simRosDisplayDialog: simRosDisplayDialog,
  simRosLoadModel: simRosLoadModel,
  simRosAuxiliaryConsoleOpen: simRosAuxiliaryConsoleOpen,
  simRosClearIntegerSignal: simRosClearIntegerSignal,
  simRosClearFloatSignal: simRosClearFloatSignal,
  simRosSetObjectQuaternion: simRosSetObjectQuaternion,
  simRosSetArrayParameter: simRosSetArrayParameter,
  simRosGetObjectParent: simRosGetObjectParent,
  simRosSetJointState: simRosSetJointState,
  simRosGetBooleanParameter: simRosGetBooleanParameter,
  simRosSetJointTargetPosition: simRosSetJointTargetPosition,
  simRosGetFloatingParameter: simRosGetFloatingParameter,
  simRosSetObjectParent: simRosSetObjectParent,
  simRosGetObjectChild: simRosGetObjectChild,
  simRosSetModelProperty: simRosSetModelProperty,
  simRosSetUISlider: simRosSetUISlider,
  simRosSetObjectPose: simRosSetObjectPose,
  simRosEndDialog: simRosEndDialog,
  simRosGetCollectionHandle: simRosGetCollectionHandle,
  simRosSetIntegerParameter: simRosSetIntegerParameter,
  simRosTransferFile: simRosTransferFile,
  simRosGetStringSignal: simRosGetStringSignal,
  simRosGetVisionSensorDepthBuffer: simRosGetVisionSensorDepthBuffer,
  simRosReadProximitySensor: simRosReadProximitySensor,
  simRosGetLastErrors: simRosGetLastErrors,
  simRosEnablePublisher: simRosEnablePublisher,
  simRosBreakForceSensor: simRosBreakForceSensor,
};
