'use strict';

const number = Math.trunc(Math.random()* 20) + 1;
let highscore = 0;
let score = 20;

function update() {
    score--;
    document.querySelector('.highscore').textContent= highscore;
    document.querySelector('.score').textContent= score;
}

function cleaner() {
    score = 20;
    document.querySelector('.score').textContent= score;
    document.querySelector('.number').textContent = '?';
    document.querySelector('.guess').value = 0;
    document.querySelector('.message').textContent = "Start Guessing ...";
    document.querySelector('body').style.backgroundColor = '#222';
    document.querySelector('.number').style.width = '15rem';
    document.querySelector(".check").addEventListener('click', checker);
}

function win() {
    document.querySelector(".check").removeEventListener('click', checker);
    if (score > highscore)
        highscore = score;
    console.log(highscore);
    score = 21;
    document.querySelector('.number').textContent = number;
    document.querySelector('.message').textContent = "Correct Number";
    document.querySelector('body').style.backgroundColor = '#60b347';
    document.querySelector('.number').style.width = '30rem';
    
}

const checker = function() {
    const value = Number(document.querySelector(".guess").value);
    
    if (score < 1)
        document.querySelector('.message').textContent= "You lost the game!"
    else if (value === number)
        win();
    else if (value < 1 || value > 20)
        document.querySelector('.message').textContent = "You should be from 1 to 20";
    else {
        if (value > number)
            document.querySelector(".message").textContent = "Too High";
        else
            document.querySelector(".message").textContent = "Too Low";
        update();
    }
}

document.querySelector(".check").addEventListener('click', checker);
document.querySelector(".again").addEventListener('click', cleaner);