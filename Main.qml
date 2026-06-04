import QtQuick
import QtQuick.Controls 2.15
Window {
    width: 360
    height: 640
    visible: true
    title: qsTr("Thermostat")
    color: "#1a1a2e"
    property int temperature: backend.temperature

    Text {
        text: "23.0°C"
        color: "white"
        font.pixelSize: 28
        font.bold: true
        anchors.top: parent.top
        anchors.left: parent.left
        anchors.margins: 20
    }

    Text {
        text: "Clear | Air Excellent"
        color: "#aaaaaa"
        font.pixelSize: 14
        anchors.top: parent.top
        anchors.left: parent.left
        anchors.topMargin: 55
        anchors.leftMargin: 20
    }
    Rectangle{
        width: 250
        height: 250
        radius: 125
        anchors.centerIn: parent
        color: backend.circleColor

        Text {
            anchors.centerIn: parent
            color: "white"
            text: temperature+"°C"
            font.pixelSize: 40
        }

    }
    Canvas {
        id: arc
        width: 270
        height: 270
        anchors.centerIn: parent
        Connections {
               target: backend
               function onTemperatureChanged() {
                   arc.requestPaint()
               }
           }
        onPaint: {
            var startAngle = Math.PI * 0.75
            var endAngle = Math.PI * 0.75 + (temperature / 40) * Math.PI * 1.5
            var ctx = getContext("2d")
            ctx.clearRect(0, 0, width, height)
            ctx.strokeStyle = "#f0c040"
            ctx.lineWidth = 13
            ctx.beginPath()
            ctx.arc(135, 135, 120, startAngle, endAngle)
            ctx.stroke()
        }
    }


    Row {
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 60
        spacing: 30
        Rectangle {
            width: 45
            height: 45
            radius: 22
            color: "#0f3460"
            Text {
                anchors.centerIn: parent
                text: "▼"
                font.pixelSize: 22
                color: "white"
            }
            MouseArea {
                anchors.fill: parent
                onClicked: backend.decrease()
            }
        }

        Rectangle {
            width: 45
            height: 45
            radius: 22
            color: "#0f3460"
            Text {
                anchors.centerIn: parent
                text: "▲"
                font.pixelSize: 22
                color: "white"
            }
            MouseArea {
                anchors.fill: parent
                onClicked: backend.increase()
            }
        }

        Rectangle {
            width: 45
            height: 45
            radius: 22
            color: "#0f3460"
            Text {
                anchors.centerIn: parent
                text: "⚙"
                font.pixelSize: 22
                color: "white"
            }
            MouseArea {
                anchors.fill: parent
                onClicked: settingsPopup.open()
            }
        }
        Rectangle {
            width: 45
            height: 45
            radius: 22
            color: "#0f3460"
            Text {
                anchors.centerIn: parent
                text: "⏻"
                font.pixelSize: 22
                color: "white"
                }
            MouseArea {
                anchors.fill: parent
                onClicked: Qt.quit()
            }
        }
    }
    Popup {
        id: settingsPopup
        width: 350
        height: 600
        anchors.centerIn: parent
        modal: true
        background: Rectangle {
            color: "#0f3460"
            radius: 15
        }
        Text {
            anchors.centerIn: parent
            text: "Settings"
            color: "white"
            font.pixelSize: 22
        }
        Rectangle {
            width: 30
            height: 30
            radius: 15
            color: "#e94560"
            anchors.top: parent.top
            anchors.right: parent.right
            Text {
                anchors.centerIn: parent
                text: "✕"
                color: "white"
                font.pixelSize: 16
            }
            MouseArea {
                anchors.fill: parent
                onClicked: settingsPopup.close()
            }
        }
    }
}



