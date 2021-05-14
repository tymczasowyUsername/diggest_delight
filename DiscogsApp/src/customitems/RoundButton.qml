import QtQuick 2.12
import QtQuick.Controls 2.5

Rectangle {
    id: root

    function onClickedCallback() { console.log("Default callback") }
    function onLongClickCallback() { }
    property url image

    implicitHeight: 20
    implicitWidth: 20

    radius: height / 2

    Image {
        source: image
        anchors.centerIn: parent
        fillMode: Image.PreserveAspectFit
    }

    MouseArea {
        id: mouseArea

        onClicked: {
            onClickedCallback()
        }

        onPressAndHold: {
            onLongClickCallback()
        }
    }
}
