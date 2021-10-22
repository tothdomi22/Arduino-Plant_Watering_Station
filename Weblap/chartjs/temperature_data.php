<?php

header('Content-Type: application/json');

define('DB_HOST', 'localhost');
define('DB_USERNAME', '******'); //database username
define('DB_PASSWORD', '******'); //database jelszó
define('DB_NAME', '******'); //database név

$mysqli = new mysqli(DB_HOST, DB_USERNAME, DB_PASSWORD, DB_NAME);

if(!$mysqli){
  die("Connection failed: " . $mysqli->error);
}

$query = sprintf("SELECT reading_time, temperature FROM SensorData");

$result = $mysqli->query($query);

$data = array();
foreach ($result as $row) {
  $data[] = $row;
}

$result->close();

$mysqli->close();

print json_encode($data);
