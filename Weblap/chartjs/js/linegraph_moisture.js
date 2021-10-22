$(document).ready(function(){
    $.ajax({
        url : "https://diywateringstation.000webhostapp.com/chartjs/moisture_data.php",
        type : "GET",
        success : function(data){
            console.log(data);

            var id = [];
            var soil_moisture = [];

            for(var i in data) {
                id.push(data[i].reading_time);
                soil_moisture.push(data[i].moisture);
            }

            var chartdata = {
                labels: id,
                datasets: [
                    {
                        label: "moisture",
                        fill: false,
                        lineTension: 0.1,
                        backgroundColor: "rgba(59, 89, 152, 0.75)",
                        borderColor: "rgba(59, 89, 152, 1)",
                        pointHoverBackgroundColor: "rgba(59, 89, 152, 1)",
                        pointHoverBorderColor: "rgba(59, 89, 152, 1)",
                        data: soil_moisture
                    }
                ]
            };

            var ctx = $("#mycanvas");

            var LineGraph = new Chart(ctx, {
                type: 'line',
                data: chartdata
            });
        },
        error : function(data) {

        }
    });
});
