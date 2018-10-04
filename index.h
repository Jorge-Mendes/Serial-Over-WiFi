const char MAIN_page[] PROGMEM = R"=====(
<!DOCTYPE html>
<html>
<body>

<div id="serialoverwifi">
<h1>Serial over WiFi</h1>
  Use this buttons to test wifi connection to AP<BR>
	<button type="button" onclick="sendData(1)">LED ON</button>
	<button type="button" onclick="sendData(0)">LED OFF</button><BR><BR>
</div>

<div>
  Verify if NodeMCU LED is ON or OFF<BR>
  LED State is : <span id="LEDState">NA</span><BR><BR>
</div>


<div>
  <h3>Text or commands to send</h3>
	<form id="txt_form" name="frmText">
     <textarea name="form_text" rows="10" cols="40"></textarea><BR>
  </form>
  <input type="submit" value="Send" onclick="SendText()" /><BR><BR>
</div>


<div>
	<h3>Received text or commands</h3> 
	<form id="ADCValue" name="frmText2">
        <textarea readonly="true" name="form_text2" rows="10" cols="40" style="overflow:auto">0</textarea><BR>
  </form>	
  <input type="submit" value="Clear screen" onclick="ClearText()" /><BR>    
</div>

<script>
function sendData(led) {
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
}, 2000); //2000mSeconds update rate

function getData() {
  var xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
      document.getElementById("ADCValue").form_text2.value=
      this.responseText;
    }
  };
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
