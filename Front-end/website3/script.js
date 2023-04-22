//Animate Skills on Scroll
const skills = document.querySelectorAll('li');

window.addEventListener('scroll', checkScroll);

function checkScroll() {
    const triggerBottom = window.innerHeight * 0.9;

    skills.forEach(skill => {
        const skillTop = skill.getBoundingClientRect().top;

        if(skillTop < triggerBottom) {
            skill.classList.add('animate');
        } else {
            skill.classList.remove('animate');
        }
    });
}
