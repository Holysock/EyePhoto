import QtQuick 2.0

Item {
    id: captureButton
    //property string text
    property alias source : captureImage.source

    width: 140
    height: 140

    signal clicked

    Rectangle {
        id: buttonFrame
        anchors.fill: parent

        gradient: Gradient {
            GradientStop { position: 0.0; color: mouseArea.pressed ? "blue" : "lightsteelblue" }
            GradientStop { position: 1.0; color: mouseArea.pressed ? "lightsteelblue" : "blue" }
        }

        radius: 30
        antialiasing: true
    }

    /*Text {
        id: captureText
        anchors.centerIn: buttonFrame
        text: captureButton.text
    }*/

    Image {
        id: captureImage
        anchors.fill: buttonFrame
        fillMode: Image.PreserveAspectFit
    }

    MouseArea {
        id: mouseArea
        anchors.fill: buttonFrame
        onClicked: { captureButton.clicked(); }
    }
}
