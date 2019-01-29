
"use strict";

let ObjectGroupData = require('./ObjectGroupData.js');
let ProximitySensorData = require('./ProximitySensorData.js');
let VisionSensorData = require('./VisionSensorData.js');
let VisionSensorDepthBuff = require('./VisionSensorDepthBuff.js');
let ScriptFunctionCallData = require('./ScriptFunctionCallData.js');
let ForceSensorData = require('./ForceSensorData.js');
let JointSetStateData = require('./JointSetStateData.js');
let VrepInfo = require('./VrepInfo.js');

module.exports = {
  ObjectGroupData: ObjectGroupData,
  ProximitySensorData: ProximitySensorData,
  VisionSensorData: VisionSensorData,
  VisionSensorDepthBuff: VisionSensorDepthBuff,
  ScriptFunctionCallData: ScriptFunctionCallData,
  ForceSensorData: ForceSensorData,
  JointSetStateData: JointSetStateData,
  VrepInfo: VrepInfo,
};
