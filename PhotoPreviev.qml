import QtQuick 2.0

import itpms.PhotoBooth.io 1.0

Item {
    property alias source: preview.source
    property alias path: photoManager.path
    property alias configuration: controls.configuration

    signal closed

    Image {
        id: preview
        //anchors.fill: parent
        /*anchors {
            top: parent.top
            bottom: parent.bottom
            left: parent.right
            //right: parent.right - controls.buttonsPanelWidth
        }*/
        x: 0
        y: 0
        width: parent.width - controls.buttonsPanelWidth
        height: parent.height

        fillMode: Image.PreserveAspectFit
        smooth: true
    }

    MouseArea {
        anchors.fill: parent
        onClicked: {
            parent.closed();
        }
    }

    PhotoPreviewControls {
        id: controls
        anchors.fill: parent

        onClose: parent.closed()
        onPrintPhoto: photoManager.printCurrentImage(controls.configuration)
    }

    PhotoManager {
        id: photoManager
    }
}
