const api_key = "98fc7f20d17e28aeb0513c253629c50f";
const lat = 25.6866;
const lon = -100.3161;
const url = `https://api.openweathermap.org/data/2.5/weather?lat=${lat}&lon=${lon}&units=metric&appid=${api_key}`;
async function obtenerTemperatura(){
    try{
    const respuesta = await fetch(url);
    const datos = await respuesta.json();
    if(datos.main && datos.main.temp){
        document.getElementById("temp").innerHTML =
        datos.main.temp + "°C";  
    }
    else{
    
        document.getElementById("temp").innerHTML=
        "No se pudo obtener la temperatura";
    }
}catch (error){
   console.error("Error al obtener la temperatura:",error);
document.getElementById("temp").innerHTML = "Error al obtener la temperatura";}
}
obtenerTemperatura();
setInterval(obtenerTemperatura,60000);