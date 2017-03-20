import QtQuick 2.5
import QtQuick.Window 2.2
import QtMultimedia 5.5

import itpms.PhotoBooth.config 1.0

Window {
    id: window
    visible: true
    width: 640
    height: 480
    title: qsTr("Photo Both")
    visibility: "FullScreen"
    color: "black"

    property bool capturing : true

    /*state: "PhotoCapture"

    states: [
        State {
            name: "PhotoCapture"
            StateChangeScript {
                script: {
                    camera.start()
                }
            }
        }
    ]*/

    Camera {
        id: camera
        deviceId: QtMultimedia.availableCameras[0].deviceId
        captureMode: Camera.CaptureStillImage

        imageCapture {
            onImageCaptured: {
                photoPreview.source = preview
            }
            onImageSaved: {
                photoPreview.path = path
                window.capturing = false
            }
        }
    }

    VideoOutput {
        //anchors.fill: parent
        source: camera

        x: 0
        y: 0
        width: parent.width - controls.buttonsPanelWidth
        height: parent.height

        autoOrientation: true

        visible: window.capturing
    }

    CaptureControls {
        id: controls
        anchors.fill: parent
        camera: camera
        countDown: countdown
        visible: window.capturing
    }

    CaptureCountdown {
        id: countdown
        anchors.fill: parent

        onFinished: camera.imageCapture.captureToLocation(config.captureBasePath)
    }

    PhotoPreviev {
        id: photoPreview
        anchors.fill: parent
        onClosed: {
            window.capturing = true
            camera.start()
        }
        visible: !window.capturing
        focus: visible

        configuration: config
    }

    Configuration {
        id: config
    }
}
