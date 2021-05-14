
import QtQuick 2.12
import QtQuick.Layouts 1.15

import "qrc:/customitems" as Items

Items.FlickableDelegate {
  //  z: 150

    rightFlickBackgroundItem: heard
    leftFlickBackgroundItem: rating

    onFlickedRight: {
        console.log("Mark as heard " + index)
       // releaseController.markAsHeard(index)
       // releaseController.moveToCollection(index)
    }

    onFlickedLeft: {
        // releaseController.removeFromWantlist(index)
    }

    flickableContentItem: content

    Component {
        id: content

        Rectangle {
            anchors.fill: parent
            color: "orange"

            RowLayout {
                anchors.fill: parent

                Item {
                    Layout.fillHeight: true
                    Layout.margins: {
                        left: parent.width / 20
                    }

                    Layout.preferredWidth: parent.width / 3

                    Image {
                        anchors.fill: parent
                        source: url
                        fillMode: Image.PreserveAspectFit
                    }
                }

                Column {
                    Layout.fillHeight: true
                    Layout.preferredWidth: parent.width / 5
                    Layout.margins: {
                        top: parent.height / 10
                        bottom: parent.height / 10
                    }

                    Text {
                        text: artist
                        color: "white"
                    }
                    Text {
                        text: title
                        color: "white"
                    }
                }

                Text {
//                    text: condition
                    color: "white"
                }
            }
        }
    }

    Component {
        id: heard

        Rectangle {
            anchors.fill: parent
            color: "yellow"

            Text {
                anchors.centerIn: parent
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                font.pixelSize: 20
                text: "MARK AS HEARD"
                color: "white"
            }
        }
    }

    Component {
        id: rating

        Rectangle {

            anchors.fill: parent
            color: "green"
            property int currentRating: 0

            Row {
                spacing: parent.width / 10
                Repeater {
                    model: 5
                    delegate: Item {
                        Image {
                            source: index > currentRating ? "" : ""
                        }
                        MouseArea {
                            anchors.fill: parent

                            onClicked: currentRating = index
                        }
                    }
                }
            }
        }
    }
}
