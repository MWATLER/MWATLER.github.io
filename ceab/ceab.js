function SetContent(content) {
    console.log("SetContent("+content+")");
    //Make all fields invisible
    var elem=document.querySelectorAll('#tab-content div');
    console.log("elem.length:"+elem.length);
    for(var i=0; i<elem.length; ++i) {
        elem[i].classList.add("fade");
        elem[i].classList.add("hidden");
        elem[i].classList.remove("active");
    }
    elem=document.querySelectorAll('.header-info');
    for(var i=0; i<elem.length; ++i) {
        elem[i].classList.add("hidden");
    }
    //Make fields visible for the selected content
    if(content=='Documents') {
        elem=document.querySelectorAll('.header-info');
        for(var i=0; i<elem.length; ++i) {
            elem[i].classList.remove("hidden");
        }
        elem=document.querySelector('#Documents');
    } else if(content=='mth110') {
        elem=document.querySelector('#mth110');
    } else if(content=='sem105') {
        elem=document.querySelector('#sem105');
    } else if(content=='sep101') {
        elem=document.querySelector('#sep101');
    } else if(content=='sea100') {
        elem=document.querySelector('#sea100');
    } else if(content=='mec110') {
        elem=document.querySelector('#mec110');
    } else if(content=='mth200') {
        elem=document.querySelector('#mth200');
    } else if(content=='ses260') {
        elem=document.querySelector('#ses260');
    } else if(content=='sep200') {
        elem=document.querySelector('#sep200');
    } else if(content=='sed200') {
        elem=document.querySelector('#sed200');
    } else if(content=='chm300') {
        elem=document.querySelector('#chm300');
    } else if(content=='sem305') {
        elem=document.querySelector('#sem305');
    } else if(content=='ses300') {
        elem=document.querySelector('#ses300');
    } else if(content=='seh300') {
        elem=document.querySelector('#seh300');
    } else if(content=='btd210') {
        elem=document.querySelector('#btd210');
    } else if(content=='btp405') {
        elem=document.querySelector('#btp405');
    } else if(content=='sem405') {
        elem=document.querySelector('#sem405');
    } else if(content=='sep400') {
        elem=document.querySelector('#sep400');
    } else if(content=='sep420') {
        elem=document.querySelector('#sep420');
    } else if(content=='btp500') {
        elem=document.querySelector('#btp500');
    } else if(content=='sea400') {
        elem=document.querySelector('#sea400');
    if(elem!=undefined) {
        SetActive(elem);
    }
}

function SetActive(elem) {
    elem.classList.remove("hidden");
    elem.classList.remove("fade");
    elem.classList.add("fade-in");
    elem.classList.add("active");
}
