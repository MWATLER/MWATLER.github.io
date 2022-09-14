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
    if(content=='Summary') {
        elem=document.querySelectorAll('.header-info');
        for(var i=0; i<elem.length; ++i) {
            elem[i].classList.remove("hidden");
        }
        elem=document.querySelector('#Summary');
    } else if(content=='Workshops') {
        elem=document.querySelector('#Workshops');
    } else if(content=='Project') {
        elem=document.querySelector('#Project');
    } else if(content=='OfficeHours') {
        elem=document.querySelector('#OfficeHours');
    } else if(content=='Contact') {
        elem=document.querySelector('#Contact');
    } else if(content=='Week1') {
        elem=document.querySelector('#Week1');
    } else if(content=='Week2') {
        elem=document.querySelector('#Week2');
    } else if(content=='Week3') {
        elem=document.querySelector('#Week3');
    } else if(content=='Week4') {
        elem=document.querySelector('#Week4');
    } else if(content=='Week5') {
        elem=document.querySelector('#Week5');
    } else if(content=='Week6') {
        elem=document.querySelector('#Week6');
    } else if(content=='Week7') {
        elem=document.querySelector('#Week7');
    } else if(content=='Week8') {
        elem=document.querySelector('#Week8');
    } else if(content=='Week9') {
        elem=document.querySelector('#Week9');
    } else if(content=='Week10') {
        elem=document.querySelector('#Week10');
    } else if(content=='Week11') {
        elem=document.querySelector('#Week11');
    } else if(content=='Week12') {
        elem=document.querySelector('#Week12');
    } else if(content=='Week13') {
        elem=document.querySelector('#Week13');
    } else if(content=='Week14') {
        elem=document.querySelector('#Week14');
    }
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
