$(document).ready(function(){
	$.ajax({
		url : "https://diywateringstation.000webhostapp.com/chartjs/humidity_data.php",
		type : "GET",
		success : function(data){
			console.log(data);

			var id = [];
			var air_humidity = [];

			for(var i in data) {
				id.push(data[i].reading_time);
				air_humidity.push(data[i].humidity);
			}

			var chartdata = {
				labels: id,
				datasets: [
					{
						label: "humidity",
						fill: false,
						lineTension: 0.1,
						backgroundColor: "rgba(59, 89, 152, 0.75)",
						borderColor: "rgba(59, 89, 152, 1)",
						pointHoverBackgroundColor: "rgba(59, 89, 152, 1)",
						pointHoverBorderColor: "rgba(59, 89, 152, 1)",
						data: air_humidity
					}
				]
			};

			var ctx = $("#mycanvas3");

			var LineGraph = new Chart(ctx, {
				type: 'line',
				data: chartdata
			});
		},
		error : function(data) {

		}
	});
});
