import QtQuick 2.0

import itpms.PhotoBooth.config 1.0

FocusScope {
    id: photoPreviewControls
    property bool previewAvailable : false
    property Configuration configuration

    property int buttonsPanelWidth : buttonPaneShadow.width

    signal close
    signal printPhoto
    signal mail

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
                //text: "Close"
                source: "icons/cross.png"
                onClicked: photoPreviewControls.close();
            }

            CaptureButton {
                //text: "Print"
                source: "icons/printer.png"
                visible: configuration.printEnabled
                onClicked: photoPreviewControls.printPhoto();
            }

            CaptureButton {
                //text: "Send via E-Mail"
                source: "icons/camera.png"
                visible: configuration.smtpEnabled
            }

            CaptureButton {
                //text: "Download to Phone"
                source: "icons/camera.png"
                visible: configuration.downloadEnabled
            }
        }
    }
}

