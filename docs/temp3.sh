#!/bin/bash
echo "Content-type: text/html"
echo ""



#digitemp_DS9097 -s /dev/ttyUSB0  -i -c /var/www/tmp/.digitemprc    


#get temperature from first sensor

Temper0=$(digitemp_DS9097 -s /dev/ttyUSB0 -t 0 -r 100 -c /var/www/tmp/.digitemprc -q -o %.C) 
#echo $Temper0
T0=Temper0
if [[$T0 -gt 100]]
  then
    T0=100
fi

if [[$T0 -le 20]]
  then 
     T0=20
fi

T0=$(($T0-20))
angle=$(($T0*27/8-225))

arrow0='<polygon points="240,240 425,248 425,252 240,260" stroke="red" fill="white" transform="rotate('$angle' 250 250)"/>'


# get temperature from second  sensor 

Temper1=$(digitemp_DS9097 -s /dev/ttyUSB0 -t 1 -r 100 -c /var/www/tmp/.digitemprc -q -o %.C) 
#echo $Temper1 
T0=Temper1
if [[$T0 -gt 100]]
  then
    T0=100
fi

if [[$T0 -le 20]]
  then 
     T0=20
fi

T0=$(($T0-20))
angle=$(($T0*27/8-225))

arrow1='<polygon points="240,240 425,248 425,252 240,260" stroke="red" fill="white" transform="rotate('$angle' 250 250)"/>'



string=$(cat << _EOF_

<!DOCTYPE html>
<html>
<head>
   <title> Котел Ыгарский 99 </title>
   <meta charset="utf-8" http-equiv="refresh" content="60">
</head>
<style>


.aligncenter {
    text-align: center;
}

div{

    display: flex;
    justify-content: center;

   }

</style>
  <body>

<div>


  <svg xmlns="http://www.w3.org/2000/svg" version="1.1" viewBox =" 0 0 500 500" >

<!--  width="500" height="500" preserveAspectRatio="xMidYMid meet" >  -->

  <defs>

   <style type="text/css"><![CDATA[
       #streak {
         stroke: white;
	 stroke-width: 3;

          }
	#MarkStreak{
        stroke       : red;
        stroke-width : 5;
	      
          }
      ]]>
    .text1
    {
      	font  : 36px Times new roman;
	fill  :	white;
    	stroke: white; 
     }
    .text2
    {
      	font  : 36px Times new roman;
	fill  :	black;
    	stroke: black; 
     }


   </style> 

    <symbol id="sector">
      <line  x1 ="410" y1 = "250" x2 = "440" y2 = "250" id="MarkStreak" transform="rotate(-225.00  250 250)"  /> 
      <line  x1 ="410" y1 = "250" x2 = "430" y2 = "250" id="streak" transform="rotate(-218.25  250 250)"  />
      <line  x1 ="410" y1 = "250" x2 = "430" y2 = "250" id="streak" transform="rotate(-211.50  250 250)"  /> 
      <line  x1 ="410" y1 = "250" x2 = "430" y2 = "250" id="streak" transform="rotate(-204.75  250 250)"  />
      <line  x1 ="410" y1 = "250" x2 = "430" y2 = "250" id="streak" transform="rotate(-198.00  250 250)"  /> 
    </sector>

  </defs>

  <circle cx="250" cy="250" r="200" fill="black"/>


  <text x="250" y="30" text-anchor="middle" class="text2"> Выход из котла </text> 


  <!-- scale -->
  <!-- 8 sectors -->
  <use xlink:href="#sector" transform="rotate(000.00 250 250)" />
  <use xlink:href="#sector" transform="rotate(033.75 250 250)" />
  <use xlink:href="#sector" transform="rotate(067.50 250 250)" />
  <use xlink:href="#sector" transform="rotate(101.25 250 250)" />
  <use xlink:href="#sector" transform="rotate(135.00 250 250)" />
  <use xlink:href="#sector" transform="rotate(168.75 250 250)" />
  <use xlink:href="#sector" transform="rotate(202.50 250 250)" />
  <use xlink:href="#sector" transform="rotate(236.25 250 250)" />

  <!-- and  last  streak -->
  <line  x1 ="410" y1 = "250" x2 = "440" y2 = "250" id="MarkStreak" transform="rotate(+045.00  250 250)"/>

  <!-- MARK -->

  <text x=144 y=363 text-anchor="start" class="text1" >  20  </text>           
  <text x=102 y=206 text-anchor="start" class="text1" >  40  </text>
  <text x=250 y=120 text-anchor="middle" class="text1" >  60  </text>
  <text x=390 y=206 text-anchor="end" class="text1" >  80  </text>
  <text x=360 y=363 text-anchor="end" class="text1" >  100  </text>

  $arrow0
  <text x="250" y="400" text-anchor="middle" class="text1"> $Temper0 &degC </text>

 </svg>

</div>


  <!-------------------------------------- Second termometr --------------------------------------------------------->



  <svg xmlns="http://www.w3.org/2000/svg" version="1.1" viewBox ="0 0 500 500">

<!-- width="500" height="500" preserveAspectRatio="xMidYMid meet" >    -->

  <defs>

   <style type="text/css"><![CDATA[
       #streak {
         stroke: white;
	 stroke-width: 3;
         }

	#MarkStreak{
        stroke       : red;
        stroke-width : 5;
        }
    ]]>
   .text1
   {
      	font  : 36px Times new roman;
	fill  :	white;
	stroke: white; 
   }

  </style> 

   <symbol id="sector">
     <line  x1 ="410" y1 = "250" x2 = "440" y2 = "250" id="MarkStreak" transform="rotate(-225.00  250 250)"  /> 
     <line  x1 ="410" y1 = "250" x2 = "430" y2 = "250" id="streak" transform="rotate(-218.25  250 250)"  />
     <line  x1 ="410" y1 = "250" x2 = "430" y2 = "250" id="streak" transform="rotate(-211.50  250 250)"  /> 
     <line  x1 ="410" y1 = "250" x2 = "430" y2 = "250" id="streak" transform="rotate(-204.75  250 250)"  />
     <line  x1 ="410" y1 = "250" x2 = "430" y2 = "250" id="streak" transform="rotate(-198.00  250 250)"  /> 
   </sector>

 </defs>

  <text x="250" y="30" text-anchor="middle" class="text2"> "Обратка" </text> 
 
  <circle cx="250" cy="250" r="200" fill="black"/>

   <!-- scale -->
   <!-- 8 sectors -->
   <use xlink:href="#sector" transform="rotate(000.00 250 250)" />
   <use xlink:href="#sector" transform="rotate(033.75 250 250)" />
   <use xlink:href="#sector" transform="rotate(067.50 250 250)" />
   <use xlink:href="#sector" transform="rotate(101.25 250 250)" />
   <use xlink:href="#sector" transform="rotate(135.00 250 250)" />
   <use xlink:href="#sector" transform="rotate(168.75 250 250)" />
   <use xlink:href="#sector" transform="rotate(202.50 250 250)" />
   <use xlink:href="#sector" transform="rotate(236.25 250 250)" />

   <!-- and  last  streak -->
   <line  x1 ="410" y1 = "250" x2 = "440" y2 = "250" id="MarkStreak" transform="rotate(+045.00  250 250)"/>

   <!-- MARK -->

   <text x=144 y=363 text-anchor="start" class="text1" >  20  </text>           
   <text x=102 y=206 text-anchor="start" class="text1" >  40  </text>
   <text x=250 y=120 text-anchor="middle" class="text1" >  60  </text>
   <text x=390 y=206 text-anchor="end" class="text1" >  80  </text>
   <text x=360 y=363 text-anchor="end" class="text1" >  100  </text>

   $arrow1
   <text x="250" y="400" text-anchor="middle" class="text1"> $Temper1 &degC </text>

 </svg>




</html>

_EOF_
)

echo $string
