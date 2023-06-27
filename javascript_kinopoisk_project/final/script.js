let main = document.querySelector('.main');

main.addEventListener('click', ()=>{
    main.classList.add('search_active');
})


let movieNameRef = document.getElementById("movie-name");
let searchBtn = document.getElementById("search-btn");
let result = document.getElementById("result");

let enter = document.getElementById('movieForm');

let getMovie = () => {
    result.innerHTML = '';
    let tempInput = document.getElementById("movie-name");
    let movieName = tempInput.value;
    let url = `https://www.omdbapi.com/?s=${movieName}&apikey=${key}`;
    console.log(url)
    if (movieName.length <= 0) {
        result.innerHTML = `<h3 class="msg">Please Enter A Movie Name</h3> `;
    } else {
        fetch(url)
            .then((resp) => resp.json())
            .then((data) => {
                console.log(data)
                if (data.Response === 'True') {
                    let dataPosters = data.Search.map(element => element.Poster);
                    console.log(dataPosters);
                    dataPosters.forEach(element =>{
                        // Создаем новый элемент "img"
                        let img = document.createElement('img');

                        img.setAttribute('src', element);
                        img.setAttribute('alt', 'no poster found');
                        img.classList.add('result-img')

                        result.appendChild(img);
                    })
                } else {
                    result.innerHTML = `<img src="../assets/didnotunderstand.svg" class="didnotunderstand"  alt="">`;
                }
                console.log(data);
            });
    }
};


searchBtn.addEventListener("click", getMovie);

movieNameRef.addEventListener('keydown', function (event) {
        if (event.keyCode === 13 ) {
            event.preventDefault();
            getMovie();
        }
    })
