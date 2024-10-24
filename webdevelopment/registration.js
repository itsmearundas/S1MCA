function nope(){
    var name = document.getElementById("name").value;
    var phone = document.getElementById("phone").value;
    var dob = document.getElementById("dob").value;
    var email = document.getElementById("email").value;
    var password = document.getElementById("password").value;
    var conformpassword  = document.getElementById("conformpassword").value;
    var letters = /^[A-Za-z]+$/;  
    var numbers = /^[0-9]+$/; 
    var email_val = /^([a-zA-Z0-9_\.\-])+\@(([a-zA-Z0-9\-])+\.)+([a-zA-Z0-9]{2,4})+$/;  

    
    if(name == "" || phone == "" || dob == "" || email == "" || password == "" || conformpassword == ""  ){
        alert("please enter valid details");
        return false;
    }
    else if(password.length < 5 || password.length > 8 ){
        alert("password length must be between 5 and 8");
        return false;
    }
    else if(password != conformpassword){
        alert("password and conformpassword does not matching");
        return false;
    }
    else{
        window.location.href = "./redirect.html";  
        return false;
    }
}