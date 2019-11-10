import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.5

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")
    Button {
        id: writeButton
        anchors.top: parent.top
        text: "Scrivi"
        onClicked: {

            console.log("Wrote " + fileWriter.write("test", "Hello"))
        }
    }
    Button {
        id: readButton
        anchors.bottom: parent.bottom
        text: "Leggi"
        onClicked: {

            console.log("Read " + fileWriter.read("test"))
        }
    }

    Button {
        id: mkdirButton

        text: "Create dir"
        onClicked: {
            console.log("Read " + fileWriter.mkdir("testdir"))
        }
    }
}
