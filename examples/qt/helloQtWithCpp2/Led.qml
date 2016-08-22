import QtQuick 2.4

LedForm {

    buttonOn.onClicked: {
        console.log("Led On...")
        led.on()
    }

    buttonOff.onClicked: {
        console.log("Led Off...")
        led.off()
    }

}
