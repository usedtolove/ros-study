import QtQuick 2.4
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.0

//ui file

Item {

    //export alias to Led.qml for event handle
    property alias buttonOn : btnOn
    property alias buttonOff : btnOff

    width: 400
    height: 400

    Button {
        id: btnOn
        x: 84
        y: 90
        text: qsTr("Led On")
    }

    Button {
        id: btnOff
        x: 229
        y: 90
        text: qsTr("Led Off")
    }
}
