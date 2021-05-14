import QtQuick 2.0
import QtQuick.Layouts 1.12
import QtQml.Models 2.12

Rectangle {
    id: root

    z:5 //temporary

    anchors.fill: parent
    color: "black"

    ColumnLayout {
        anchors.fill: parent

        Item {
            Layout.preferredHeight: parent.height * 0.2
            Layout.fillWidth: true

            Text {
                text: "DiggersDelight"
                anchors.centerIn: parent
            }
        }

        GridView {
            Layout.fillWidth: true
            Layout.fillHeight: true
            Layout.margins: {
                rightMargin = 0.1 * parent.width
                leftMargin = 0.1 * parent.width
            }


            model: ListModel {
                id: screensModel

                ListElement {
                    name: "Inventory"
                    image: ""
                    color_: "green"
                }

                ListElement {
                    name: "Dig session"
                    image: ""
                    color_: "violet"
                }
                ListElement {
                    name: "Browse"
                    image: ""
                    color_: "red"
                }
                ListElement {
                    name: "Account"
                    image: ""
                    color_: "blue"
                }
            }

            delegate: Rectangle {
                color: color_
                height: 50
                width: 50
            }
        }
    }
}

