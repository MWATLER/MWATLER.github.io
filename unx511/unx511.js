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
    } else if(content=='OfficeHours') {
        elem=document.querySelector('#OfficeHours');
    } else if(content=='Contact') {
        elem=document.querySelector('#Contact');
    } else if(content=='MidTerm') {
        elem=document.querySelector('#MidTerm');
    } else if(content=='FinalAssessment') {
        elem=document.querySelector('#FinalAssessment');
    } else if(content=='Quiz1') {
        elem=document.querySelector('#Quiz1');
    } else if(content=='Quiz2') {
        elem=document.querySelector('#Quiz2');
    } else if(content=='Quiz3') {
        elem=document.querySelector('#Quiz3');
    } else if(content=='Quiz4') {
        elem=document.querySelector('#Quiz4');
    } else if(content=='Quiz5') {
        elem=document.querySelector('#Quiz5');
    } else if(content=='Quiz6') {
        elem=document.querySelector('#Quiz6');
    } else if(content=='Quiz7') {
        elem=document.querySelector('#Quiz7');
    } else if(content=='Quiz8') {
        elem=document.querySelector('#Quiz8');
    } else if(content=='Quiz9') {
        elem=document.querySelector('#Quiz9');
    } else if(content=='Quiz10') {
        elem=document.querySelector('#Quiz10');
    } else if(content=='Quiz11') {
        elem=document.querySelector('#Quiz11');
    } else if(content=='Lab1') {
        elem=document.querySelector('#Lab1');
    } else if(content=='Lab2') {
        elem=document.querySelector('#Lab2');
    } else if(content=='Lab3') {
        elem=document.querySelector('#Lab3');
    } else if(content=='Lab4') {
        elem=document.querySelector('#Lab4');
    } else if(content=='Lab5') {
        elem=document.querySelector('#Lab5');
    } else if(content=='Lab6') {
        elem=document.querySelector('#Lab6');
    } else if(content=='Lab7') {
        elem=document.querySelector('#Lab7');
    } else if(content=='Lab8') {
        elem=document.querySelector('#Lab8');
    } else if(content=='Lab9') {
        elem=document.querySelector('#Lab9');
    } else if(content=='Lab10') {
        elem=document.querySelector('#Lab10');
    } else if(content=='Lab11') {
        elem=document.querySelector('#Lab11');
    } else if(content=='Assignment1') {
        elem=document.querySelector('#Assignment1');
    } else if(content=='Assignment2') {
        elem=document.querySelector('#Assignment2');
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
