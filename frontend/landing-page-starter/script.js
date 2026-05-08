let destination = document.querySelector('.destination')
let nextBtn = document.querySelector('.next')
let prevBtn = document.querySelector('.prev')

let BgImgs = [
    "../images/Destinations/kedarnath-temple.webp",
    '../images/Destinations/azhimala.webp',
    '../images/Destinations/marinaBeach.jpg',
    '../images/Destinations/meghalaya.jpg',
    '../images/Destinations/rameshwaram.jpeg',
]
   let arrindex= 0

function banner(index){

   if(index==1){
    arrindex+=1
        if(arrindex>4){
            arrindex=0
        }
    
    destination.style.backgroundImage = `url(${BgImgs[arrindex]})`
     }
    else{
         arrindex-=1
        if(arrindex<0){
            arrindex=4
        }
    
    destination.style.backgroundImage = `url(${BgImgs[arrindex]})`

    }
  


}