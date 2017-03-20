import QtQuick 2.0

Item {
    id: countdown
    visible: false

    function startCountDown() {
        countDownAnimation.start();
    }

    signal finished

    Text {
        id: countDownText
        text: "5"

        anchors.centerIn: parent

        color: "red"

        font {
            bold: true
            pixelSize: 300
        }
    }

    SequentialAnimation {
        id: countDownAnimation
        running: false

        onStopped: countdown.finished()

        PropertyAction {
            target: countDownText
            property: "text"
            value: "5"
        }
        PropertyAction {
            target: countdown
            property: "visible"
            value: "true"
        }
        PauseAnimation {
            duration: 1000
        }
        PropertyAction {
            target: countDownText
            property: "text"
            value: "4"
        }
        PauseAnimation {
            duration: 1000
        }
        PropertyAction {
            target: countDownText
            property: "text"
            value: "3"
        }
        PauseAnimation {
            duration: 1000
        }
        PropertyAction {
            target: countDownText
            property: "text"
            value: "2"
        }
        PauseAnimation {
            duration: 1000
        }
        PropertyAction {
            target: countDownText
            property: "text"
            value: "1"
        }
        PauseAnimation {
            duration: 1000
        }
        /*PropertyAction {
            target: countDownText
            property: "text"
            value: "Smile!"
        }
        PauseAnimation {
            duration: 100
        }*/
        PropertyAction {
            target: countdown
            property: "visible"
            value: "false"
        }
    }
}
