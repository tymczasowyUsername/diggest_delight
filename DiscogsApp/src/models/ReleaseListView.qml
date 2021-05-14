import QtQuick 2.12
import QtQuick.Controls 2.5
import QtQml.Models 2.15

ListView {
    id: root

    model:
//        releaseController.wantlist

        ListModel {
        id: modell
        ListElement {
            artist: "Kerri Chandler"
            title: "Rain"
            url: "file:///C:/Users/TOm/Downloads/vinyl.jpg"
            label: "Madhouse"
            year: "2000"
            rating: 5
            wantmeter: 3
        }
        ListElement {
            artist: "Masters At Work"
            title: "123"
            url: "file:///C:/Users/TOm/Downloads/vinyl.jpg"
            label: "MAW"
            year: "2005"
            rating: 4
            wantmeter: 3
        }
        ListElement {
            artist: "ABC"
            title: "123"
            url: "file:///C:/Users/TOm/Downloads/vinyl.jpg"
            label: "AAA"
            year: "2005"
            rating: 3
            wantmeter: 5
        }
    }

//    property alias backgroundDelegate
    MouseArea {
       // anchors.fill: parent
        onClicked: {
            modelPlaceHolder.focused = true
        }
        onPressAndHold: {
            modelPlaceHolder.focused = false
        }
    }
}
