import QtQuick 2.4

LedForm {

    buttonOn.onClicked: {
        console.log("Led On...")
        myClass.myFun()
    }

    buttonOff.onClicked: {
        console.log("Led Off...")
    }

}
