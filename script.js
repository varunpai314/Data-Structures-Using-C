let body = document.getElementsByTagName("body");
let div = document.createElement("div");
div.setAttribute("class", "container");
let editor = document.createElement("textarea");
editor.setAttribute("id", "editor");
editor.placeholder = `#include<stdio.h>

int main(){
    printf("Hello World");
  return 0;
}`;
editor.value = `${URL}`;
div.appendChild(editor);
body[0].appendChild(div);


