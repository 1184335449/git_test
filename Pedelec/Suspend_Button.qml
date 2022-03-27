import QtQuick 2.0

import QtQuick.Controls 2.5
import QtQuick.Controls 1.3
import QtQuick.Controls.Styles 1.3

Item {
    Button
    {
        id: suspend_Button
        width: 40
        height: 80
        x:0
        y:220
        style: ButtonStyle {
           background: Rectangle{
               color:{
                   if(control.hovered)//指针悬浮时
                   {
                       if(control.pressed){//指针按下时
                           "#CFCFCF"
                       }
                       else{
                           "#828282"
                       }
                   }
                   else{"#CFCFCF"}//指针未进入按钮
               }
           }
        }
        MouseArea {
            anchors.fill: parent
            property real lastX: 0
            property real lastY: 0
            onPressed: {
                //鼠标按下时，记录鼠标初始位置
                lastX = mouseX
                lastY = mouseY
            }
            onPositionChanged: {
                if (pressed) {
                        //鼠标按住的前提下，坐标改变时，计算偏移量，应用到目标item的坐标上即可
                        suspend_Button.x += mouseX - lastX
                        suspend_Button.y += mouseY - lastY
                        if(suspend_Button.x<80){ //左
                            suspend_Button.width=40
                            suspend_Button.height= 80
                            suspend_Button.x=0
                        }
                        if( suspend_Button.y<80){//上
                            suspend_Button.width=80
                            suspend_Button.height= 40
                            suspend_Button.y=0
                        }
                        if( suspend_Button.x>=904){//右
                            suspend_Button.width=40
                            suspend_Button.height= 80
                            suspend_Button.x=984
                            if(suspend_Button.y>=480) suspend_Button.y=520
                        }
                        if( suspend_Button.y>=480){//下
                            suspend_Button.width=80
                            suspend_Button.height= 40
                            suspend_Button.y=560
                            if(suspend_Button.x>=904) suspend_Button.x=944
                        }
                    }
                }
            }
    }
}
