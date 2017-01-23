import QtQuick 2.5
import QtQuick.Controls 1.4
import QtQuick.Layouts 1.2

Item {
    width: 640
    height: 480

    property alias slider1: sliderresolution
    property alias slider2: sliderloops
    property alias slider3: sliderx
    property alias slider4: slidery
    property alias slider5: sliderradius
    property alias slider6: sliderv01
    property alias slider7: sliderlength
    property alias slider8: sliderv02
    property alias radioButton1: radiona
    property alias radioButton2: radioJacobi
    property alias radioButton3: radiovertical
    property alias radioButton4: radiohorizontal
    property alias circle: circle
    property alias linear: linear
    property alias compile: compile

    ExclusiveGroup {
        id: group1
    }

    Text {
        id: text1
        x: 26
        y: 41
        text: qsTr("REsolution")
        font.pixelSize: 12
    }

    Text {
        id: text2
        x: 30
        y: 90
        text: qsTr("Loops")
        font.pixelSize: 12
    }

    Text {
        id: text3
        x: 26
        y: 138
        text: qsTr("Method")
        font.pixelSize: 12
    }

    Text {
        id: text4
        x: 26
        y: 218
        text: qsTr("Choose Boundary type")
        font.pixelSize: 12
    }

    Text {
        id: text5
        x: 346
        y: 32
        text: qsTr("For circle")
        font.pixelSize: 12
    }

    Text {
        id: text6
        x: 342
        y: 218
        text: qsTr("For linear")
        font.pixelSize: 12
    }

    Slider {
        id: sliderresolution
        x: 26
        y: 62
        width: 200
        stepSize: 1
        maximumValue: 100

        Text {
            id: text20
            x: 200
            width: 24
            height: 14
            text: sliderresolution.value
            font.pixelSize: 12
        }
    }

    Slider {
        id: sliderloops
        x: 26
        y: 111
        width: 200
        stepSize: 1
        maximumValue: 100

        Text {
            id: text21
            x: 200
            text: sliderloops.value
            font.pixelSize: 12
        }
    }

    GridLayout {
        id: gridLayout
        x: 346
        y: 62
        width: 242
        height: 100
        rows: 4
        columns: 3

        Text {
            id: text7
            width: 10
            text: qsTr("x co-ord")
            font.pixelSize: 12
        }

        Slider {
            id: sliderx
            width: 200
            maximumValue: 100
            stepSize: 1
        }

        Text {
            id: text8
            text: sliderx.value
            font.pixelSize: 12
        }

        Text {
            id: text9
            text: qsTr("y co-ord")
            font.pixelSize: 12
        }

        Slider {
            id: slidery
            width: 200
            stepSize: 1
            maximumValue: 100
        }

        Text {
            id: text10
            text: slidery.value
            font.pixelSize: 12
        }

        Text {
            id: text11
            text: qsTr("Radius")
            font.pixelSize: 12
        }

        Slider {
            id: sliderradius
            width: 200
            stepSize: 1
            maximumValue: 100
        }

        Text {
            id: text12
            text: sliderradius.value
            font.pixelSize: 12
        }

        Text {
            id: text13
            text: qsTr("V0")
            font.pixelSize: 12
        }

        Slider {
            id: sliderv01
            width: 200
            stepSize: 1
            maximumValue: 100
        }

        Text {
            id: text14
            text: sliderv01.value
            font.pixelSize: 12
        }
    }

    GridLayout {
        id: gridLayout1
        x: 342
        y: 291
        width: 276
        height: 68
        rows: 2
        columns: 3

        Text {
            id: text16
            text: qsTr("Length")
            font.pixelSize: 12
        }

        Slider {
            id: sliderlength
            width: 100
            stepSize: 1
            maximumValue: 100
        }

        Text {
            id: text17
            text: sliderlength.value
            font.pixelSize: 12
        }

        Text {
            id: text18
            text: qsTr("V0")
            font.pixelSize: 12
        }

        Slider {
            id: sliderv02
            width: 100
            stepSize: 1
            maximumValue: 100
        }

        Text {
            id: text19
            text: sliderv02.value
            font.pixelSize: 12
        }
    }

    Text {
        id: text15
        x: 342
        y: 239
        text: qsTr("Alignment")
        font.pixelSize: 12
    }

    Button {
        id: circle
        x: 409
        y: 168
        text: qsTr("Add Circle boundary")
    }

    Button {
        id: linear
        x: 398
        y: 365
        text: qsTr("Add Linear Boundary")
    }

    Image {
        id: image
        x: 26
        y: 252
        width: 294
        height: 206
        fillMode: Image.PreserveAspectFit
        source: "qrc:/qtquickplugin/images/template_image.png"

        Text {
            id: text22
            x: 40
            y: 204
            text: qsTr("Output Data")
            font.pixelSize: 12
        }
    }

    Button {
        id: compile
        x: 447
        y: 435
        text: qsTr("Compile")
    }

    ProgressBar {
        id: progressBar
        x: 73
        y: 344
        maximumValue: 100
    }

    Column {
        id: column
        x: 26
        y: 161
        width: 70
        height: 51

        RadioButton {
            id: radiona
            text: qsTr("N/A")
            exclusiveGroup: group1
        }

        RadioButton {
            id: radioJacobi
            text: qsTr("Jacobi")
            exclusiveGroup: group1
        }
    }

    Column {
        id: column1
        x: 405
        y: 239
        width: 97
        height: 46

        ExclusiveGroup {
            id: group2
        }

        RadioButton {
            id: radiovertical
            text: qsTr("Vertical")
            exclusiveGroup: group2
        }

        RadioButton {
            id: radiohorizontal
            text: qsTr("Horizontal")
            exclusiveGroup: group2
        }
    }
}
