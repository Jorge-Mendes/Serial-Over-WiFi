const char MAIN_page[] PROGMEM = R"=====(
<!DOCTYPE html>
<html>
<head>



<style>

input[type=submit] {
    background-color: #2196F3;
    border: none;
    color: white;
    padding: 7px 25px;
    text-align: center;
    text-decoration: none;
    display: inline-block;
    font-size: 16px;
    margin: 4px 2px;
    cursor: pointer;
    border-radius: 6px;
}

.switch {
  position: relative;
  display: inline-block;
  width: 60px;
  height: 34px;
}

.switch input {display:none;}

.slider {
  position: absolute;
  cursor: pointer;
  top: 0;
  left: 0;
  right: 0;
  bottom: 0;
  background-color: #ccc;
  -webkit-transition: .4s;
  transition: .4s;
}

.slider:before {
  position: absolute;
  content: "";
  height: 26px;
  width: 26px;
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

body {
  background: #FFF;
}

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
  font-size: 16px;
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
  margin: 0px 2px;
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
  font-size: 18px;
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

/* ---- */

textarea {
  border:solid 2px #CCC;
  width: 98%;
}


</style>
  <meta name="viewport" content="width=device-width">   <!-- https://stackoverflow.com/a/14581134 -->
  <div id="serialoverwifi">
    <h1>Serial over WiFi</h1>
  </div>
</head>



<body>
  <!--
    <div>
      Use this buttons to test WiFi connection with AP<br>
      <button type="button" onclick="sendData(1)">LED ON</button>
      <button type="button" onclick="sendData(0)">LED OFF</button><br><br>
    </div>
    <div>
      Verify if NodeMCU LED is ON or OFF<BR>
      LED State is : <span id="LEDState">NA</span><br><br>
    </div>
  -->
  
  <div>
    <h3>Test WiFi connection with NodeMCU using the onboard LED:</h3>
    LED State is: <span id="LEDState">OFF</span><br>
    <label class="switch">
      <input type="checkbox" id="myCheck" onclick="sendData()">   <!--checked-->
      <span class="slider round"></span>
    </label><br><br>
  </div>

  <div>
    <h3>Predefined commands to send:</h3>
    <form class="select" id="commands_form" name="frmCommands">
      <select id="commands">
        <option value="comando_def" disabled="disabled" selected="selected">Select one command</option>
        <option value="comando_1">Comando 1 dasdsadas das d asd as das d as</option>
        <option value="comando_2">Comando 2</option>
        <option value="comando_3">Comando 3</option>
        <option value="comando_4">Comando 4</option>
        <option value="comando_5">Comando 5</option>
      </select>
    </form>
    <input type="submit" value="Send" onclick="SendCommand()"/><br><br>
  </div>

  <div>
    <h3>Text or command to send:</h3>
	  <form id="txt_form" name="frmText">
      <textarea name="form_text" rows="1"></textarea><br>    <!-- cols="45" -->
    </form>
    <input type="submit" value="Send" onclick="SendText()"/><br><br>
  </div>

  <div>
	  <h3>Received text or commands:</h3> 
	  <form id="ADCValue" name="frmText2">
      <textarea name="form_text2" rows="10" readonly="true" style="overflow:auto;">Starting...</textarea><br>    <!-- cols="45" -->
    </form>
    <div style="width: 100%; overflow: hidden;">
      <div style="width: 100px; float: left;">
        <input type="submit" value="Clear screen" onclick="ClearText()"/>
      </div>
      <div style="margin-left: 170px; margin-top: 10px;">
        <label class="control control--checkbox">Autoscroll
          <input id="autoscroll" type="checkbox" checked="checked"/>
          <div class="control__indicator"></div>
        </label>
      </div>
    </div>
    <br>
  </div>

<script>



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
      document.getElementById("ADCValue").form_text2.value=
      this.responseText;
    }
  };

  if(document.getElementById("autoscroll").checked == true) {
    if(document.getElementById("ADCValue").form_text2.selectionStart == document.getElementById("ADCValue").form_text2.selectionEnd) {
      document.getElementById("ADCValue").form_text2.scrollTop = document.getElementById("ADCValue").form_text2.scrollHeight;
    }
  }
  
  xhttp.open("GET", "readADC", true);
  xhttp.send();
}


strText = "";
function SendText()
{
	var xhttp = new XMLHttpRequest();
		
	strText = "?texto=" + document.getElementById("txt_form").form_text.value;
	
	xhttp.open("GET", "ajax_inputs" + strText, true);
	xhttp.send(null);
}


function SendCommand()
{
  var xhttp = new XMLHttpRequest();
  var e = document.getElementById("commands")
  strText = "?texto=" + e.options[e.selectedIndex].text;;
  xhttp.open("GET", "ajax_inputs" + strText, true);
  xhttp.send(null);
}


clrText = "";
function ClearText()
{
  var xhttp = new XMLHttpRequest();
    
  clrText = "?texto2=" + document.getElementById("ADCValue").form_text2.value;
  
  xhttp.open("GET", "clear_text" + clrText, true);
  xhttp.send(null);
}



</script>
</body>
</html>
)=====";
