<?php


$servername = "localhost";

// database név
$dbname = "********";
// database username
$username = "********";
// database jelszó
$password = "********";

$api_key_value = "tPmAT5Ab3j7F9";

$api_key= $distance = $moisture = $humidity = $temperature = "";

if ($_SERVER["REQUEST_METHOD"] == "POST") {
    $api_key = test_input($_POST["api_key"]);
    if($api_key == $api_key_value) {
        $distance = test_input($_POST["distance"]);
        $moisture = test_input($_POST["moisture"]);
        $humidity = test_input($_POST["humidity"]);
        $temperature = test_input($_POST["temperature"]);
        
        // Create connection
        $conn = new mysqli($servername, $username, $password, $dbname);
        // Check connection
        if ($conn->connect_error) {
            die("Connection failed: " . $conn->connect_error);
        } 
        
        $sql = "INSERT INTO SensorData (distance, moisture, humidity, temperature)
        VALUES ('" . $distance . "', '" . $moisture . "', '" . $humidity . "', '" . $temperature . "')";
        
        if ($conn->query($sql) === TRUE) {
            echo "New record created successfully";
        } 
        else {
            echo "Error: " . $sql . "<br>" . $conn->error;
        }
    
        $conn->close();
    }
    else {
        echo "Wrong API Key provided.";
    }

}
else {
    echo "No data posted with HTTP POST.";
}

function test_input($data) {
    $data = trim($data);
    $data = stripslashes($data);
    $data = htmlspecialchars($data);
    return $data;
}
