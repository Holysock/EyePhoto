import QtQuick 2.0
import QtMultimedia 5.5

FocusScope {
    property Camera camera
    property CaptureCountdown countDown
    property bool previewAvailable : false

    property int buttonsPanelWidth : buttonPaneShadow.width

    id: captureControls

    Rectangle {
        id: buttonPaneShadow
        anchors.top: parent.top
        anchors.right: parent.right
        height: parent.height
        width: buttonsColumn.width + 16
        color: "black"
        Column {
            anchors {
                /*right: parent.right
                top: parent.top*/
                centerIn: parent
                margins: 8
            }

            id: buttonsColumn
            spacing: 8

            CaptureButton {
                //text: "Capture"
                source: "icons/camera.png"
                visible: camera.imageCapture.ready
                onClicked: countDown.startCountDown()
            }
        }
    }
}
