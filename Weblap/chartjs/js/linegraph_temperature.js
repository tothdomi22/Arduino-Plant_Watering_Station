$(document).ready(function(){
    $.ajax({
        url : "https://diywateringstation.000webhostapp.com/chartjs/temperature_data.php",
        type : "GET",
        success : function(data){
            console.log(data);

            var id = [];
            var air_temperature = [];

            for(var i in data) {
                id.push(data[i].reading_time);
                air_temperature.push(data[i].temperature);
            }

            var chartdata = {
                labels: id,
                datasets: [
                    {
                        label: "temperature",
                        fill: false,
                        lineTension: 0.1,
                        backgroundColor: "rgba(59, 89, 152, 0.75)",
                        borderColor: "rgba(59, 89, 152, 1)",
                        pointHoverBackgroundColor: "rgba(59, 89, 152, 1)",
                        pointHoverBorderColor: "rgba(59, 89, 152, 1)",
                        data: air_temperature
                    }
                ]
            };

            var ctx = $("#mycanvas2");

            var LineGraph = new Chart(ctx, {
                type: 'line',
                data: chartdata
            });
        },
        error : function(data) {

        }
    });
});
