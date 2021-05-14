import QtQuick 2.12
import QtQuick.Controls 2.5
import QtQml.Models 2.15
import DiggersDelight 1.0

import "qrc:/screens" as Screens
import "qrc:/models" as Models

ApplicationWindow {
    id: app

    width: 340
    height: 680
    visible: true
    title: qsTr("DiggersDelight")

    Screens.MainScreen {
        id: main
        z: -10
    }
    
    Flickable {
        id: background

        anchors.fill: parent
        contentWidth: swipeView.contentWidth
        contentX: swipeView.contentX * 0.15
        interactive: false

        Image {
            source: "file:///C:/Users/TOm/Downloads/vinyl.jpg"
            fillMode: Image.PreserveAspectFit
        }
    }

    Rectangle {
        id: modelPlaceHolder

        property bool focused

        width: parent.width * 0.99
        height: parent.height * 0.99
        anchors.centerIn: parent
        color: "black"
        opacity: 0.5
//        border.color: "white"
//        border.width: 5
//        radius: 15

        ReleaseController {
            id: releaseController
        }

        ObjectModel {
            id: listModel

            Models.ReleaseListView { //wantlist
                id: wantlist

//                interactive: false
                height: modelPlaceHolder.height
                width: modelPlaceHolder.width

//                model: releaseController.wantlist

                delegate: Models.CollectionDelegate {
                    height: wantlist.height / 5
                    width: wantlist.width
                }
            }

            Models.ReleaseListView { //collection
                id: collection

                height: modelPlaceHolder.height
                width: modelPlaceHolder.width
               // model: releaseController.collection

                delegate: Models.WantlistDelegate {
                    height: wantlist.height / 5
                    width: wantlist.width
                }
            }

            Item {

                id: browse

                height: modelPlaceHolder.height
                width: modelPlaceHolder.width
            }

            Item {
                id: account

                height: modelPlaceHolder.height
                width: modelPlaceHolder.width
            }
        }

    ListView {
        id: swipeView

        //property bool focused: false
        interactive: modelPlaceHolder.focused
        snapMode: ListView.SnapOneItem
        highlightRangeMode: ListView.StrictlyEnforceRange
        orientation: ListView.Horizontal
//        flickableDirection: ListView.HorizontalFlick
        anchors.fill: parent

        model: listModel
    }
        PageIndicator {
            id: indicator

            count: swipeView.count
            currentIndex: swipeView.currentIndex

            anchors.bottom: swipeView.bottom
            anchors.horizontalCenter: parent.horizontalCenter

            delegate: Text {
                text: listModel.children.toString()
                color: "white"
            }
        }
    }
}
