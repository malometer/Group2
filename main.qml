import QtQuick 2.5
import QtQuick.Controls 1.4
import QtQuick.Dialogs 1.2

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("Boundary Problem")

    menuBar: MenuBar {
        Menu {
            title: qsTr("File")
            MenuItem {
                text: qsTr("&Open")
                onTriggered: console.log("Open action triggered");
            }
            MenuItem {
                text: qsTr("Exit")
                onTriggered: Qt.quit();
            }
        }
    }

    MainForm {
        anchors.fill: parent
        circle.onClicked: createcircle()
        linear.onClicked: messageDialog.show(sliderresolution.value)//change values


        function createcircle() {
            var i, j, i2, j2
            for (i=0; i<=grid; i++) {
                  for(j=0; j<= grid; j++) {


                      i2 = i - sliderx.value;
                      i2 = i2*i2;

                      j2 = j - slidery.value;
                      j2 = j2*j2;

                      if (bounds[j][i] == true) {

                      if (i2+j2<a*a) {

                  values[j][i]=V0;
                          bounds[j][i]=false;

                      } else {

                          bounds[j][i]=true;

                          square_dist= i2 + j2;

                          dist = sqrt(square_dist);
                          closeness=abs(dist-a);

                          if( closeness < 0.4 ) {
                              values[j][i]=V0;
                              bounds[j][i]=false;

                          }

                      }

                      }
                  }
              }
          }
       }


    MessageDialog {
        id: messageDialog
        title: qsTr("May I have your attention, please?")

        function show(caption) {
            messageDialog.text = caption;
            messageDialog.open();
        }
    }

}
