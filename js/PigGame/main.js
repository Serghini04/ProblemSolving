let scores, roundScore, activePlayer, dice, gamePlaying;
scores = [0,0];
roundScore = 0;
activePlayer = 0;
gamePlaying = true;
init();

function init(){
  document.querySelector('#score-0').textContent = '0' ;
  document.querySelector('#score-1').textContent = '0' ;
  document.querySelector('#current-0').textContent = '0';
  document.querySelector('#current-1').textContent = '0';
  document.querySelector('.dice').style.display = 'none';
  document.querySelector('.player-0-panel').classList.remove('winner');
  document.querySelector('.player-1-panel').classList.remove('winner');
  document.querySelector('.player-0-panel').classList.remove('active');
  document.querySelector('.player-1-panel').classList.remove('active');
  document.querySelector('.player-0-panel').classList.add('active');
};

function nextPlayer(){
  if(activePlayer === 0){
    roundScore = 0;
    document.querySelector('.player-1-panel').classList.toggle('active');
    document.querySelector('.player-0-panel').classList.toggle('active');
    document.querySelector('#current-'+ activePlayer).textContent = String(roundScore);
    activePlayer = 1;

  } else if( activePlayer === 1){
    roundScore = 0;
    document.querySelector('.player-1-panel').classList.toggle('active');
    document.querySelector('.player-0-panel').classList.toggle('active');
    document.querySelector('#current-'+ activePlayer).textContent = String(roundScore);
    activePlayer = 0;
  }
}

document.querySelector('.btn-roll').addEventListener('click', () => {

  dice = Math.floor((Math.random() * 6) + 1);
  document.querySelector('.dice').src = `img/dice-${dice}.png`;
  document.querySelector('.dice').style.display = 'block';

  if(dice !== 1){
    roundScore += dice;
    document.querySelector('#current-'+ activePlayer).textContent = roundScore;
  } else
    nextPlayer();
});

document.querySelector('.btn-hold').addEventListener('click', () => {

  scores[activePlayer] += roundScore;
  document.querySelector('#score-'+activePlayer).textContent = scores[activePlayer];

  if(scores[activePlayer] >= 5){
    console.log('won !');
    document.querySelector('.dice').style.display = 'none';
    document.querySelector('.btn-roll').removeEventListener(click);
    document.querySelector('.player-'+activePlayer+'-panel').classList.add('winner');
    document.querySelector('#name-'+activePlayer).classList.add('player-name');
    document.querySelector('#name-'+activePlayer).textContent = 'WINNER !';
    gamePlaying = false;
  }
  nextPlayer();
});

document.querySelector('.btn-new').addEventListener('click', () => {
  init();
  roundScore = 0;
  scores = [0,0]
  activePlayer = 0;
});




console.log(scores);
console.log(roundScore);
console.log(activePlayer);


