var enter = document.getElementById("enter");
var input = document.getElementById("userinput");
var ul = document.querySelector("ul");
var del = document.getElementsByClassName("remove");


function removeItem(event) {
	event.target.parentElement.remove();
}


function toggleDone(event) {
	if (event.target.classList.contains("list")) {
		event.target.classList.toggle("done");
	}
}

function inputLength() {
	return input.value.length;
}

function createListElement() {
	var li = document.createElement("li");
	li.className = "list";
	li.appendChild(document.createTextNode(input.value + " "));
	ul.appendChild(li);
	input.value = "";

	var button = document.createElement("button");
	button.className = "remove";
	button.appendChild(document.createTextNode("Remove"));
	li.appendChild(button);

	button.addEventListener("click", removeItem);

}

function addListAfterClick() {
	if (inputLength() > 0 && input.value !== " ") {
		createListElement();
	}
}

function addListAfterKeypress(event) {
	if (inputLength() > 0 && event.keyCode === 13 && input.value !== " ") {
		createListElement();
	}
}


for(var i = 0; i < del.length; i++) {
	del[i].addEventListener("click", removeItem);
}


document.addEventListener("click", toggleDone);

enter.addEventListener("click", addListAfterClick);

input.addEventListener("keypress", addListAfterKeypress);