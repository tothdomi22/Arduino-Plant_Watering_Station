<!DOCTYPE html>
<html><body>
<?php

$servername = "localhost";

// database név
$dbname = "*********";
// database username
$username = "**********";
// database jelszó
$password = "**********";

$conn = new mysqli($servername, $username, $password, $dbname);

if ($conn->connect_error) {
    die("Connection failed: " . $conn->connect_error);
} 

$sql = "SELECT id, distance, moisture, humidity, temperature, reading_time FROM SensorData ORDER BY id DESC";

echo '<table cellspacing="5" cellpadding="5">
      <tr> 
        <td>ID</td> 
        <td>Distance</td> 
        <td>Moisture</td>
        <td>Humidity</td>
        <td>Temperature</td>
        <td>Timestamp</td> 
      </tr>';
 
if ($result = $conn->query($sql)) {
    while ($row = $result->fetch_assoc()) {
        $row_id = $row["id"];
        $row_distance = $row["distance"];
        $row_moisture = $row["moisture"]; 
        $row_humidity = $row["humidity"]; 
        $row_temperature = $row["temperature"]; 
        $row_reading_time = $row["reading_time"];
      
        echo '<tr> 
                <td>' . $row_id . '</td> 
                <td>' . $row_distance . '</td> 
                <td>' . $row_moisture . '</td>
                <td>' . $row_humidity . '</td>
                <td>' . $row_temperature . '</td>
                <td>' . $row_reading_time . '</td> 
              </tr>';
    }
    $result->free();
}

$conn->close();
?> 
</table>
</body>
</html>
