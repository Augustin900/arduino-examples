const char index_html[] = R"=====(
<html>
<head>
  <link rel="stylesheet" href="https://stackpath.bootstrapcdn.com/bootstrap/4.3.1/css/bootstrap.min.css">
  <script src="https://cdnjs.cloudflare.com/ajax/libs/jscolor/2.0.4/jscolor.min.js"></script>
  <style>
    body{
      display: flex;
      justify-content: center;
      align-items: center;
      overflow: hidden;
    }
    .dhtContainer{
      position: absolute;
      transform: translateY(50px);
    }
    .container{
      position: absolute;
      transform: translateX(175px);
    }
  </style>
  <title>DHT Weather Monitor with RGB LED Controller</title>
</head>
<body>
  <div class="dhtContainer">
  <span id="temperatureC">%TEMPERATUREC%</span>
  <span class="units">&deg;C</span>
  <span class="dht-labels">/</span> 
  <span id="temperatureF">%TEMPERATUREF%</span>
  <span class="units">&deg;F</span>
  <span class="dht-labels">/</span>
  <span id="humidity">%HUMIDITY%</span>
  <span class="units">%</span>
</div> 

  <div class="container">
    <a class="btn btn-primary btn-lg" href="#" id="change_color" role="button">Change Color</a>
    <input class="jscolor {onFineChange:'update(this)'}" id="rgb">
  </div>
   <script>
  function update(picker) {
    document.getElementById('rgb').innerHTML = Math.round(picker.rgb[0]) + ', ' +  Math.round(picker.rgb[1]) + ', ' + Math.round(picker.rgb[2]);
    document.getElementById("change_color").href="?r" + Math.round(picker.rgb[0]) + "g" +  Math.round(picker.rgb[1]) + "b";
  }
setInterval(function ( ) {
  var xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
      document.getElementById("temperatureC").innerHTML = this.responseText;
    }
  };
  xhttp.open("GET", "/temperatureC", true);
  xhttp.send();
}, 2000);
setInterval(function ( ) {
  var xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
      document.getElementById("temperatureF").innerHTML = this.responseText;
    }
  };
  xhttp.open("GET", "/temperatureF", true);
  xhttp.send();
}, 2000);
setInterval(function ( ) {
  var xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
      document.getElementById("humidity").innerHTML = this.responseText;
    }
  };
  xhttp.open("GET", "/humidity", true);
  xhttp.send();
}, 2000);
  </script>
</body>
</html>
)=====";