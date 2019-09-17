const char MAIN_page[] PROGMEM = R"=====(
<!DOCTYPE html>
<html>
<head>



<style>

input[type=submit] {
    background-color: #2196F3;
    border: none;
    color: white;
    padding: 10px 24px 8px 22px;
    text-align: center;
    text-decoration: none;
    display: inline-block;
    /*font-size: 16px;*/
    margin: 4px 2px;
    cursor: pointer;
    border-radius: 6px;

    font-size: 13px;

    // https://www.daveoncode.com/2013/01/03/custom-input-type-submit-safari-mobile-css/
    -webkit-appearance: none;
    -moz-appearance: none;
    -ms-appearance: none;
    appearance: none;
  
}

.switch {
  position: relative;
  display: inline-block;
  /*width: 60px;
  height: 34px;*/
  width: 55px;
  height: 29px;
}

.switch input {display:none;}

.slider {
  position: absolute;
  cursor: pointer;
  top: 0;
  left: 0;
  right: 0;
  bottom: 0;
  /*background-color: #ccc;*/
  background-color: #aaa;
  -webkit-transition: .4s;
  transition: .4s;
}

.slider:before {
  position: absolute;
  content: "";
  /*height: 26px;
  width: 26px;*/
  height: 21px;
  width: 21px;
  left: 4px;
  bottom: 4px;
  background-color: white;
  -webkit-transition: .4s;
  transition: .4s;
}

input:checked + .slider {
  background-color: #2196F3;
}

input:focus + .slider {
  box-shadow: 0 0 1px #2196F3;
}

input:checked + .slider:before {
  -webkit-transform: translateX(26px);
  -ms-transform: translateX(26px);
  transform: translateX(26px);
}

/* Rounded sliders */
.slider.round {
  border-radius: 34px;
}

.slider.round:before {
  border-radius: 50%;
}



/* ------ */

/*body {
  background: #FFF;
}*/

/* Reset Select */
select {
  -webkit-appearance: none;
  -moz-appearance: none;
  -ms-appearance: none;
  appearance: none;
  outline: 0;
  box-shadow: none;
  border: 0 !important;
  background: #2196F3;
  background-image: none;
  font-size: 14px;
}
/* Custom Select */
.select {
  position: relative;
  display: block;
  <!-- width: 370px; -->
  width: 100%;
  height: 50px;
  line-height: 3;
  background: #2196F3;
  overflow: hidden;
  border-radius: 6px;
  /*margin: 0px 2px;*/
}
select {
  width: 100%;
  height: 100%;
  margin: 0;
  padding: 0 0 0 15px;
  color: #FFF;
  cursor: pointer;
}
select::-ms-expand {
  display: none;
}
/* Arrow */
.select::after {
  content: '\25BC';
  position: absolute;
  top: 0;
  right: 0;border:solid 1px gray
  bottom: 0;
  padding: 0 1em;
  background: #2196F3;
  pointer-events: none;
  color: #FFF;
}
/* Transition */
.select:hover::after {
  color: #FFF;
}
.select::after {
  -webkit-transition: .25s all ease;
  -o-transition: .25s all ease;
  transition: .25s all ease;
}

/* ------ */


.control {
  font-size: 14px;
  position: relative;
  display: block;
  margin-bottom: 15px;
  padding-left: 30px;
  padding-top: 3px;
  cursor: pointer;
}

.control input {
  position: absolute;
  z-index: -1;
  opacity: 0;
}

.control__indicator {
  position: absolute;
  top: 2px;
  left: 0;
  width: 20px;
  height: 20px;
  background: #2196F3;
}

/* Checked state */
.control input:checked ~ .control__indicator {
  background: #2196F3;
}

/* Check mark */
.control__indicator:after {
  position: absolute;
  display: none;
  content: '';
}

/* Show check mark */
.control input:checked ~ .control__indicator:after {
  display: block;
}

/* Checkbox tick */
.control--checkbox .control__indicator:after {
  top: 4px;
  left: 8px;
  width: 3px;
  height: 8px;
  transform: rotate(45deg);
  border: solid #fff;
  border-width: 0 2px 2px 0;
}



/* ----- */




/* Popup container - can be anything you want */
.popup {
    position: relative;
    display: inline-block;
    cursor: pointer;
    -webkit-user-select: none;
    -moz-user-select: none;
    -ms-user-select: none;
    user-select: none;
    width: 100%;
}

/* The actual popup */
.popup .popuptext {
    visibility: hidden;
    /*width: 160px;*/
    max-width: 200px;
    background-color: #555;
    color: #fff;
    text-align: center;
    border-radius: 6px;
    padding: 10px 10px;
    position: absolute;
    z-index: 1;
    /*bottom: 125%;*/
    bottom: 15%;  /* PORQUE MUDEI O SPAN PARA A H3 */
    left: 50%;
    /*margin-left: -80px;*/
    margin-left: -111px;
}

/* Popup arrow */
.popup .popuptext::after {
    content: "";
    position: absolute;
    top: 100%;
    left: 50%;
    margin-left: -5px;
    border-width: 5px;
    border-style: solid;
    border-color: #555 transparent transparent transparent;
}

/* Toggle this class - hide and show the popup */
.popup .show {
    visibility: visible;
    -webkit-animation: fadeIn 1s;
    animation: fadeIn 1s;
}

/* Add animation (fade in the popup) */
@-webkit-keyframes fadeIn {
    from {opacity: 0;} 
    to {opacity: 1;}
}

@keyframes fadeIn {
    from {opacity: 0;}
    to {opacity:1 ;}
}




/* ---- */

textarea {
  border:solid 2px #CCC;
  width: 98%;
}






















/* ---- */

#loader {
  /*position: absolute;*/
  position: fixed;   /* PARA NAO IR PARA O TOPO DA PAGINA */
  left: 50%;
  top: 50%;
  z-index: 1;
  width: 150px;
  height: 150px;
  margin: -32px 0 0 -32px;
  border: 6px solid #F3F3F3;
  border-radius: 50%;
  border-top: 6px solid #2196F3;
  width: 50px;
  height: 50px;
  -webkit-animation: spin 2s linear infinite;
  animation: spin 2s linear infinite;
}

@-webkit-keyframes spin {
  0% { -webkit-transform: rotate(0deg); }
  100% { -webkit-transform: rotate(360deg); }
}

@keyframes spin {
  0% { transform: rotate(0deg); }
  100% { transform: rotate(360deg); }
}

/* Add animation to "page content" */
.animate-bottom {
  position: relative;
  -webkit-animation-name: animatebottom;
  -webkit-animation-duration: 1s;
  animation-name: animatebottom;
  animation-duration: 1s
}

@-webkit-keyframes animatebottom {
  /*from { bottom:-100px; opacity:0 } */
  /*to { bottom:0px; opacity:1 } */
  from { opacity:0 }   /* PARA RETIRAR O MOVIMENTO ASCENDENTE */
  to { opacity:1 }     /* PARA RETIRAR O MOVIMENTO ASCENDENTE */
}

@keyframes animatebottom { 
  /*from{ bottom:-100px; opacity:0 } */
  /*to{ bottom:0; opacity:1 } */
  from { opacity:0 }   /* PARA RETIRAR O MOVIMENTO ASCENDENTE */
  to{ opacity:1 }      /* PARA RETIRAR O MOVIMENTO ASCENDENTE */
}

#myDiv {
  display: none;
  /*text-align: center;*/
}






#textarea1 {
    -moz-appearance: textfield-multiline;
    -webkit-appearance: textarea;
    border: solid 2px #ccc;
    font: medium -moz-fixed;
    font: -webkit-small-control;
    /*height: 28px;*/
    overflow: auto;
    padding: 2px;
    /*resize: both;
    width: 400px;*/
    overflow-y: auto;
word-break:break-all;
  /*background-color: #F9F9F9;*/
  background-color: #FFF;
width: 97.5%;
/*margin-top: 10px;
margin-bottom: 10px;*/
color:#303030;
height: 300px;
  /*white-space:pre-wrap;*/  /* PARA AQUILO DO "\R\N" */
}


#textarea2 {
    -moz-appearance: textfield-multiline;
    -webkit-appearance: textarea;
    border: solid 2px #ccc;
    font: medium -moz-fixed;
    font: -webkit-small-control;
    /*height: 28px;*/
    overflow: auto;
    padding: 2px;
    /*resize: both;
    width: 400px;*/
    overflow-y: auto;
word-break:break-all;
  /*background-color: #F9F9F9;*/
  background-color: #FFF;
width: 97.5%;
/*margin-top: 10px;
margin-bottom: 10px;*/
color:#303030;
height: 23px;
  /*white-space:pre-wrap;*/  /* PARA AQUILO DO "\R\N" */
}





</style>
  <!-- https://stackoverflow.com/a/14581134 -->
  <!--<meta name="viewport" content="width=device-width">-->
  <!-- https://github.com/tzapu/WiFiManager/blob/0749e1bdd76c811a5a554ff5cc5fe2fb02fa8dd2/extras/WiFiManager.template.html -->
  <meta name="viewport" content="width=device-width, initial-scale=1, user-scalable=no">
  
  <title>Serial over WiFi</title>

</head>



<body onload="onloadFunction()">



<!-- https://www.w3schools.com/howto/tryit.asp?filename=tryhow_css_loader5 -->
<div id="loader"></div>
<div style="display:none;" id="myDiv" class="animate-bottom">




  <div id="serialoverwifi">
    <h2>Serial over WiFi</h2>
  </div>
  <!--
    <div>
      Use this buttons to test WiFi connection with AP<br>
      <button type="button" onclick="sendData(1)">LED ON</button>
      <button type="button" onclick="sendData(0)">LED OFF</button><br><br>
    </div>
    <div>
      Verify if NodeMCU LED is ON or OFF<br>
      LED State is : <span id="LEDState">NA</span><br><br>
    </div>
  -->
  
  <div>
    <h4>Test WiFi connection with NodeMCU using the onboard LED:</h4>
    <div style="font-size: 15px;">LED State is: <span id="LEDState">ON</span></div><!--<br>-->
    <!-- https://www.w3schools.com/howto/tryit.asp?filename=tryhow_css_switch -->
    <label class="switch">
      <input type="checkbox" id="myCheck" onclick="sendData()" checked>   <!--checked-->
      <span class="slider round"></span>
    </label>
<!--<br><br>-->
  </div>






  <div>

           <div class="popup">
               <h4>Predefined commands to send:</h4>
               <!-- https://www.w3schools.com/howto/tryit.asp?filename=tryhow_js_popup -->
        <span id="myPopupPredfCmd" class="popuptext" ></span>
      </div>
    <form class="select" id="commands_form" name="frmCommands">



      
            <select id="commands">
        <option value="comando_def" disabled="disabled" selected="selected">Select one command</option>
      </select>


      
    </form>



<div style="width: 100%; overflow: hidden;">
      <div style="width: 53%; float: left;">


    <!-- https://www.w3schools.com/css/tryit.asp?filename=trycss_buttons_round -->
    <input id="mybotSendCmd" type="submit" value="Send" onclick="SendCommand()"/>
    <input id="mybotRemoveCmd" type="submit" value="Remove" onclick="removeCommandsList()"/>
      </div>
      <div style="margin-left: 57.5%; margin-top: 2px;">
      
    <form class="select" id="commands_form" name="frmCommands" style="margin: 4px 2px; height: 33px; line-height: 2;">
    <!-- https://codepen.io/ericrasch/pen/zjDBx -->
    <!-- https://freefrontend.com/css-select-boxes/ -->
    <!-- https://codepen.io/raubaca/pen/VejpQP -->
<select id="end_of_str_cmd" style="font-size: 13px;padding-left: 8px; padding-top: 0.3px;">
  <option id="nle_cmd" value="">No line ending</option>
  <option id="nl_cmd" value="%0A">Newline </option>
  <option id="cr_cmd" value="%0D">Carriage return</option>
  <option id="nl_cr_cmd" value="%0D%0A">Both NL & CR</option>
</select>
</form>
      </div>
    </div>




    
    <!--<br><br>-->
  </div>

  <div>


     <div class="popup">
    <h4>Text or command to send:</h4>
    <!-- https://www.w3schools.com/howto/tryit.asp?filename=tryhow_js_popup -->
        <span id="myPopupText" class="popuptext" ></span>
      </div>
      
	  <!--<form id="txt_form" name="frmText" style="margin-bottom:-5px;">

      <textarea name="form_text" rows="1"></textarea><br>    <!-- cols="45" -->

    <!--</form>-->






<form id="txt_form" name="frmText" style="margin-bottom:0px;">
<div id="textarea2" name="form_text2" contenteditable></div><!--<br>-->
</form>




    

    
    <div style="width: 100%; overflow: hidden;">
      <div style="width: 53%; float: left;">
    
    <input id="mybotSendText" type="submit" value="Send" onclick="SendText()"/>
    <input id="mybotAddText" type="submit" value="Add" onclick="addCommandsList()"/>
      </div>
      <div style="margin-left: 57.5%; margin-top: 2px;">
    <form class="select" id="commands_form" name="frmCommands" style="margin: 4px 2px; height: 33px; line-height: 2;">
<select id="end_of_str_txt" style="font-size: 13px;padding-left: 8px; padding-top: 0.3px;">
  <option id="nle_txt" value="">No line ending</option>
  <option id="nl_txt" value="%0A">Newline </option>
  <option id="cr_txt" value="%0D">Carriage return</option>
  <option id="nl_cr_txt" value="%0D%0A">Both NL & CR</option>
</select>
</form>
      </div>
    </div>



    
    
    <!--<br><br>-->
  </div>

  <div>
    <h4>Received text or commands:</h4>
    <!--<form id="ADCValue" name="frmText2" style="margin-bottom:-5px;">
      <textarea name="form_text2" rows="20" readonly="true" style="overflow:auto;"></textarea><!--<br>-->    <!-- cols="45" -->
    <!--</form>-->

<form id="ADCValue" name="frmText2" style="margin-bottom:0px;">
<div id="textarea1" name="form_text2" readonly="true"></div><!--<br>-->   <!-- contenteditable -->
</form>
    
    <div style="width: 100%; overflow: hidden;">
      <div style="width: 53%; float: left;">
    
<input type="submit" value="Clear" onclick="ClearText()"/>
<input id="mybotSaveLog" type="submit" value="Save" onclick="saveLog()"/>
      </div>
      <div style="margin-left: 70%; margin-top: 10px;">
    <label class="control control--checkbox">Autoscroll
          <input id="autoscroll" type="checkbox" checked="checked" style="margin-left: -20px;"/>
          <div class="control__indicator"></div>
        </label>
      </div>
    </div>
    <br>
  </div>

<!-- Disposição antiga -->
<!--    <div style="width: 100%; overflow: hidden;">
      <div style="width: 100px; float: left;">
        <input type="submit" value="Clear screen" onclick="ClearText()"/>
      </div>
      <div style="margin-left: 70%; margin-top: 10px;">
-->
      <!-- https://codepen.io/endorama/pen/axAnD -->
      <!-- https://kyusuf.com/post/completely-css-custom-checkbox-radio-buttons-and-select-boxes -->
<!--        <label class="control control--checkbox">Autoscroll
          <input id="autoscroll" type="checkbox" checked="checked" style="margin-left: -20px;"/>
          <div class="control__indicator"></div>
        </label>
      </div>
    </div>
-->







<!-- ESCOLHA DO BAUDRATE -->
  <div style="margin-top: -15px;">
    <form class="select" id="baudrate_form" name="frmCommands">
            <select id="baudrate" onchange="changeBaudRate()">
        <!--<option value="comando_def" disabled="disabled" selected="selected">Select one command</option>-->
  <option id="br_1200" value="1200">1200 baud</option>
  <option id="br_2400" value="2400">2400 baud</option>
  <option id="br_4800" value="4800">4800 baud</option>
  <option id="br_9600" value="9600">9600 baud</option>
  <option id="br_1900" value="19200">19200 baud</option>
  <option id="br_38400" value="38400">38400 baud</option>
  <option id="br_57600" value="57600">57600 baud</option>
  <!--<option id="br_74880" value="74880">74880 baud</option>-->
  <option id="br_115200" value="115200">115200 baud</option>
      </select>
    </form>
<!--<br><br>-->
  </div>
  <br>
<!-- ESCOLHA DO BAUDRATE -->






</div>



<script>


//window.onload = function() {
//  getCommandsList();
//};



function sendData() {
  led = 0
  led_state = ""
  var xhttp = new XMLHttpRequest();


  // Get the checkbox
  var checkBox = document.getElementById("myCheck");

  // If the checkbox is checked, display the output text
  if (checkBox.checked == true){
    led = 1
    led_state = "ON"
  } else {
    led = 0
    led_state = "OFF"
  }

  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
      document.getElementById("LEDState").innerHTML =
      led_state;
    }
  };
  
  
  xhttp.open("GET", "setLED?LEDstate="+led, true);
  // https://developer.mozilla.org/en-US/docs/Web/API/XMLHttpRequest/timeout
  xhttp.timeout = 100; // time in milliseconds
  xhttp.send();
}




function sendDatax(led) {
  var xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
      document.getElementById("LEDState").innerHTML =
      this.responseText;
    }
  };
  
  xhttp.open("GET", "setLED?LEDstate="+led, true);
  // https://developer.mozilla.org/en-US/docs/Web/API/XMLHttpRequest/timeout
  xhttp.timeout = 100; // time in milliseconds
  xhttp.send();
}



function addCommandsList()
{

  //if (document.getElementById("txt_form").form_text.value.length >= 1) {
    if (document.getElementById("textarea2").innerHTML.length >= 1) {

      document.getElementById("loader").style.display = "block";
  document.getElementById("myDiv").style.display = "none";
  //document.getElementById("myDiv").style.visibility = "hidden"; /* JM */
  
    var xhttp = new XMLHttpRequest();

    // https://stackoverflow.com/a/10610408
    //strText = "?texto=" + document.getElementById("txt_form").form_text.value.replace(/#/g, "%23");
    strText = "?texto=" + document.getElementById("textarea2").innerHTML.replace(/#/g, "%23");
  
    
    xhttp.open("GET", "addCommands" + strText, true);
    // https://developer.mozilla.org/en-US/docs/Web/API/XMLHttpRequest/timeout
    xhttp.timeout = 100; // time in milliseconds
    xhttp.send(null);

getCommandsList(0);

// Selecionar o novo comando
//var x = document.getElementById("commands").options.length;
//https://www.w3schools.com/jsref/tryit.asp?filename=tryjsref_select_selectedindex
//document.getElementById("commands").selectedIndex = x-1; 


    
  }
  else {
    //alert("I am an alert box!");
    document.getElementById("myPopupText").style.visibility = "visible";

document.getElementById("myPopupText").innerHTML = "You need to write a command to add!";

setTimeout ( "setToBlackText()", 2000 );
document.getElementById("mybotSendText").disabled = true
document.getElementById("mybotAddText").disabled = true;
    
  }
}


function setToBlackText ( )
{
//var popup = document.getElementById("myPopupText");
//popup.classList.toggle("show");
//  document.getElementById("mybot2").style.backgroundColor = "#333";
document.getElementById("myPopupText").style.visibility = "hidden";
document.getElementById("mybotSendText").disabled = false;
document.getElementById("mybotAddText").disabled = false;
}






function removeCommandsList() {















  if (document.getElementById("commands").selectedIndex != 0) {

      document.getElementById("loader").style.display = "block";
  document.getElementById("myDiv").style.display = "none";
  //document.getElementById("myDiv").style.visibility = "hidden"; /* JM */
  



  
  var xhttp = new XMLHttpRequest();
  var e = document.getElementById("commands")
  
  // https://stackoverflow.com/a/10610408
  strText = "?textoRemove=" + e.options[e.selectedIndex].text.replace(/#/g, "%23");
  
  
  xhttp.open("GET", "removeCommands" + strText, true);
  // https://developer.mozilla.org/en-US/docs/Web/API/XMLHttpRequest/timeout
  xhttp.timeout = 100; // time in milliseconds
  xhttp.send(null);


getCommandsList(1);


    }
  else {
    //alert("I am an alert box!");
    document.getElementById("myPopupPredfCmd").style.visibility = "visible";

    document.getElementById("myPopupPredfCmd").innerHTML = "You need to choose a command to remove!";

setTimeout ( "setToBlackPredfCmd()", 2000 );
document.getElementById("mybotSendCmd").disabled = true;
document.getElementById("mybotRemoveCmd").disabled = true;
    
  }












  



    

}








function getCommandsList(onstart) {

  var xhttp = new XMLHttpRequest();
  
  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {

      var commandsList = this.responseText.split(';');

      var element = document.getElementById("commands");

      var i;
      for(i = element.options.length - 1 ; i >= 1 ; i--)    // i >= 1 because first element
      {
          //console.log(i);
          // https://www.w3schools.com/jsref/tryit.asp?filename=tryjsref_select_remove
          element.remove(i);
      }


      // https://www.w3schools.com/jsref/tryit.asp?filename=tryjsref_select_add
      var arrayLength = commandsList.length;
      //console.log(arrayLength);
      for (var i = 0; i < arrayLength; i++) {
        if (commandsList[i].length > 0) {
          var option = document.createElement("option");
          option.text = commandsList[i];
          element.add(option);
        }
      }

// https://www.w3schools.com/jsref/tryit.asp?filename=tryjsref_select_selectedindex
document.getElementById("commands").selectedIndex = 0;


/* ==================*/
if (onstart === 0) {
  /* PARA LIMPAR A CAIXA DO COMANDO NOVO */
//document.getElementById("txt_form").form_text.value = "";
document.getElementById("textarea2").innerHTML = "";

        // Selecionar o novo comando apenas quando á adicionado um novo (ao fazer refresh não)
var x = document.getElementById("commands").options.length;
// https://www.w3schools.com/jsref/tryit.asp?filename=tryjsref_select_selectedindex
document.getElementById("commands").selectedIndex = x-1;



/* MOSTRAR O POPUP QUANDO É ADICIONADO UM COMANDO NOVO */
    //alert("I am an alert box!");
    document.getElementById("myPopupPredfCmd").style.visibility = "visible";

    document.getElementById("myPopupPredfCmd").innerHTML = "This command was added!";
setTimeout ( "setToBlackPredfCmd()", 2000 );







/* ==================*/
    



}


      
  document.getElementById("loader").style.display = "none";
  document.getElementById("myDiv").style.display = "block";
  //document.getElementById("myDiv").style.visibility = "visible"; /* JM */
      
    }
  };
  
  
  xhttp.open("GET", "getCommands", true);
  // https://developer.mozilla.org/en-US/docs/Web/API/XMLHttpRequest/timeout
  //xhttp.timeout = 100; // time in milliseconds
  xhttp.send();


}






setInterval(function() {
  // Call a function repetatively with 2 Second interval
  getData();
}, 100); //2000mSeconds update rate

function getData() {
  var xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
      //document.getElementById("ADCValue").form_text2.value = document.getElementById("ADCValue").form_text2.value + this.responseText;

      // NAO USANDO O "white-space:pre-wrap"
      //document.getElementById("ADCValue").form_text2.innerHTML = document.getElementById("ADCValue").form_text2.innerHTML + this.responseText.replace(/\n/gm, "<br>").replace(/\r/gm, "");

      // USANDO O "white-space:pre-wrap" (MAS NÃO FUNCIONA BEM)
      if (this.responseText.length > 0) {
      document.getElementById("textarea1").innerHTML = document.getElementById("textarea1").innerHTML + "<span style=\"color: red;\">" + this.responseText.replace(/\n/gm, "<br>").replace(/\r/gm, "") + "</span>";
      }
    }
  };

  if(document.getElementById("autoscroll").checked == true) {
    if(document.getElementById("textarea1").selectionStart == document.getElementById("textarea1").selectionEnd) {
      document.getElementById("textarea1").scrollTop = document.getElementById("textarea1").scrollHeight;
    }
  }

  
  
  xhttp.open("GET", "readADC", true);
  // https://developer.mozilla.org/en-US/docs/Web/API/XMLHttpRequest/timeout
  xhttp.timeout = 100; // time in milliseconds
  xhttp.send();
}


strText = "";
function SendText()
{


  //if (document.getElementById("txt_form").form_text.value.length >= 1) {
  if (document.getElementById("textarea2").innerHTML.length >= 1) {



  var xhttp = new XMLHttpRequest();

    // https://stackoverflow.com/a/10610408
  //strText = "?texto=" + document.getElementById("txt_form").form_text.value.replace(/#/g, "%23");
  strText = "?texto=" + document.getElementById("textarea2").innerHTML.replace(/#/g, "%23");

//str_history = document.getElementById("txt_form").form_text.value
str_history = document.getElementById("textarea2").innerHTML

// ######################################################################################
// ADICIONAR A TERMINACAO DA LINHA
  var e = document.getElementById("end_of_str_txt")
  strText = strText + e.options[e.selectedIndex].value;
// ######################################################################################

//str_history = str_history + e.options[e.selectedIndex].value.replace("%0A", "\n").replace("%0D", "\r");
str_history = str_history + e.options[e.selectedIndex].value.replace("%0A", "<br>").replace("%0D", "");  /* PORQUE O "white-space:pre-wrap" NÃO FUNCIONA BEM */

  // ADICIONAR COMANDO À CAIXA
  document.getElementById("textarea1").innerHTML = document.getElementById("textarea1").innerHTML + "<span style=\"color: blue;\">" + str_history + "</span>";

  
  xhttp.open("GET", "ajax_inputs" + strText, true);
  // https://developer.mozilla.org/en-US/docs/Web/API/XMLHttpRequest/timeout
  xhttp.timeout = 100; // time in milliseconds
  xhttp.send(null);



    
  }
  else {
    //alert("I am an alert box!");
    document.getElementById("myPopupText").style.visibility = "visible";

document.getElementById("myPopupText").innerHTML = "You need to write a command to send!";

setTimeout ( "setToBlackText()", 2000 );
document.getElementById("mybotSendText").disabled = true;
document.getElementById("mybotAddText").disabled = true;
    
  }


 
}




function SendCommand()
{



  if (document.getElementById("commands").selectedIndex != 0) {

      //document.getElementById("loader").style.display = "block";
  //document.getElementById("myDiv").style.display = "none";
  //document.getElementById("myDiv").style.visibility = "hidden"; /* JM */
  



  
  var xhttp = new XMLHttpRequest();
  var e = document.getElementById("commands")
  
  // https://stackoverflow.com/a/10610408
  strText = "?texto=" + e.options[e.selectedIndex].text.replace(/#/g, "%23");

  str_history = e.options[e.selectedIndex].text

// ######################################################################################
// ADICIONAR A TERMINACAO DA LINHA
  var e = document.getElementById("end_of_str_cmd")
  strText = strText + e.options[e.selectedIndex].value;
// ######################################################################################

//str_history = str_history + e.options[e.selectedIndex].value.replace("%0A", "\n").replace("%0D", "\r");
str_history = str_history + e.options[e.selectedIndex].value.replace("%0A", "<br>").replace("%0D", "");  /* PORQUE O "white-space:pre-wrap" NÃO FUNCIONA BEM */

// ADICIONAR COMANDO À CAIXA
  document.getElementById("textarea1").innerHTML = document.getElementById("textarea1").innerHTML + "<span style=\"color: blue;\">" + str_history + "</span>";
  
  
  xhttp.open("GET", "ajax_inputs" + strText, true);
  // https://developer.mozilla.org/en-US/docs/Web/API/XMLHttpRequest/timeout
  xhttp.timeout = 100; // time in milliseconds
  xhttp.send(null);



    }
  else {
    //alert("I am an alert box!");
    document.getElementById("myPopupPredfCmd").style.visibility = "visible";

    document.getElementById("myPopupPredfCmd").innerHTML = "You need to choose a command to send!";

setTimeout ( "setToBlackPredfCmd()", 2000 );
document.getElementById("mybotSendCmd").disabled = true;
document.getElementById("mybotRemoveCmd").disabled = true;
    
  }
}


function setToBlackPredfCmd ( )
{
//var popup = document.getElementById("myPopupPredfCmd");
//popup.classList.toggle("show");
//  document.getElementById("mybot2").style.backgroundColor = "#333";
document.getElementById("myPopupPredfCmd").style.visibility = "hidden";
document.getElementById("mybotSendCmd").disabled = false;
document.getElementById("mybotRemoveCmd").disabled = false;
}



//clrText = "";
function ClearText()
{
  //var xhttp = new XMLHttpRequest();
    
  //clrText = "?texto2=" + document.getElementById("ADCValue").form_text2.value;
  
  
  //xhttp.open("GET", "clear_text" + clrText, true);
  // https://developer.mozilla.org/en-US/docs/Web/API/XMLHttpRequest/timeout
  //xhttp.timeout = 100; // time in milliseconds
  //xhttp.send(null);

  document.getElementById("textarea1").innerHTML = "";
}












function saveLog(){
   const a = document.createElement("a");
   
   //const fileContent = document.getElementById("ADCValue").form_text2.value;

   // NAO USANDO O "white-space:pre-wrap"
   //const fileContent = document.getElementById("ADCValue").form_text2.innerHTML.replace(/<br>/g, "\r\n").replace(/<(?:.|\n)*?>/gm, '');
   
   // USANDO O "white-space:pre-wrap" (MAS NÃO FUNCIONA BEM)
   const fileContent = document.getElementById("textarea1").innerHTML.replace(/<br>/g, "\n").replace(/<(?:.|\n)*?>/gm, '');

    
    a.href = "data:text/plane," + encodeURIComponent(fileContent);
    var filename = formatDate();
    a.setAttribute("download", filename);
    document.body.appendChild(a);
    setTimeout(function () {
      a.click();
      document.body.removeChild(a);
    }, 200);
  }



function formatDate() {
  var date = new Date();
  
  var hours = date.getHours();
  var minutes = date.getMinutes();
  var seconds = date.getSeconds();
  var years = date.getFullYear();
  var months = date.getMonth()+1;
  var days = date.getDate();
  
  hours = hours < 10 ? '0'+hours : hours;
  minutes = minutes < 10 ? '0'+minutes : minutes;
  seconds = seconds < 10 ? '0'+seconds : seconds;
  months = months < 10 ? '0'+months : months;
  days = days < 10 ? '0'+days : days;
  
  var strTime = years + '' + months + '' + days + '_' + hours + '' + minutes + '' + seconds + '.txt';
  return strTime;
}



function changeBaudRate() {

  document.getElementById("loader").style.display = "block";
  document.getElementById("myDiv").style.display = "none";

    var x = document.getElementById("baudrate").value;
    //console.log(x);




                var xhttp = new XMLHttpRequest();
              
                // https://stackoverflow.com/a/10610408
                strText = "?baudrate=" + x;
                
              

              
              
                xhttp.open("GET", "sendBaudrate" + strText, true);
                // https://developer.mozilla.org/en-US/docs/Web/API/XMLHttpRequest/timeout
                xhttp.timeout = 100; // time in milliseconds
                xhttp.send(null);

  // Não chega a ser apresentada a página de loader porque é muito rápido
  document.getElementById("loader").style.display = "none";
  document.getElementById("myDiv").style.display = "block";

  //getBaudRate(0);

}


function getBaudRate(onstart) {

  // ESTA FUNÇÃO SO É CHAMADA NO INICIO E POR DEFEITO A PÁGINA JÁ ESTÁ NESTAS CONDIÇÕES
  //document.getElementById("loader").style.display = "block";
  //document.getElementById("myDiv").style.display = "none";

  var xhttp = new XMLHttpRequest();
  
  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {

      //console.log("_" + this.responseText + "_");
      //console.log(typeof(this.responseText));
      document.getElementById("baudrate").value = this.responseText;



    if (onstart === 0) {  
  document.getElementById("loader").style.display = "none";
  document.getElementById("myDiv").style.display = "block";
  //document.getElementById("myDiv").style.visibility = "visible"; /* JM */
    }

    
      
    }
  };
  
  
  xhttp.open("GET", "getBaudRate", true);
  // https://developer.mozilla.org/en-US/docs/Web/API/XMLHttpRequest/timeout
  //xhttp.timeout = 100; // time in milliseconds
  xhttp.send();


}



function onloadFunction() {
  getBaudRate(1);
  getCommandsList(1);
}



</script>
</body>
</html>
)=====";
