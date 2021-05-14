import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQml.Models 2.15
import QtQuick.Layouts 1.15

Item {
    id: root

    property Component flickableContentItem
    property Component rightFlickBackgroundItem
    property Component leftFlickBackgroundItem

    function rightFlickCallback() { console.log("Default right flick callback") }
    function leftFlickCallback() { console.log("Default left flick callback") }

    signal flickedRight
    signal flickedLeft

    onFlickedRight: rightFlickCallback()
    onFlickedLeft: leftFlickCallback()

    Flickable {
        id: flickable
        z: 10
        anchors.fill: parent

        MouseArea {
            anchors.fill: parent
            onClicked: {
                console.log("Clicked")
            }
        }

        Behavior on contentX { PropertyAnimation {} }

        Component.onCompleted: {
            contentItem.width = flickable.width
            contentItem.height = flickable.height
            console.log(contentItem.width)
            flickableContentItem.createObject(flickable.contentItem)
        }

        readonly property real flickDistance: contentX / 5
        opacity: Math.abs(1 / flickDistance * 20)
        onFlickDistanceChanged: {
            if (flickDistance > root.width / 10) {
                flickedLeft()
                if (!flickable.dragging) {
                    if(flickable.contentX < root.width) {
                        flickable.contentX = flickable.width
                    }
                }
            }
        }

        flickableDirection: Flickable.HorizontalFlick
}
    Loader {
        id: backgroundLoader

        property alias flickDistance: flickable.flickDistance

        anchors.fill: parent
        opacity: Math.abs(flickDistance / 50)
        active: flickDistance !== 0
        sourceComponent: flickDistance > 0 ? rightFlickBackgroundItem : leftFlickBackgroundItem
    }
}

