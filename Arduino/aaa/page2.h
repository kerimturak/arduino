const char htmlPage2[] PROGMEM = R"=====(
<!Doctype html>
<html>
<style>
.btn-group button {
  background-color: #04AA6D; /* Green background */
  border: 1px solid green; /* Green border */
  color: white; /* White text */
  padding: 10px 24px; /* Some padding */
  cursor: pointer; /* Pointer/hand icon */
  width: 25%; /* Set a width if needed */
  display: block; /* Make the buttons appear below each other */
  margin: auto;
}

.btn-group button:not(:last-child) {
  border-bottom: none; /* Prevent double borders */
}

/* Add a background color on hover */
.btn-group button:hover {
  background-color: #3e8e41;
}
</style>
<body>

  <div class="btn-group">
    <h1 style="margin: auto; width: 20%;">ATM MENU</h1>
  </div>
<div class="btn-group">
  <button>balance inquiry</button>
  <button>withdraw</button>
  <button>deposit</button>
  <button>transfer</button>
  <button>change password</button>
  <button>Credit Card</button>
  <button>exit</button>
</div>

</body>
</html>
)=====";