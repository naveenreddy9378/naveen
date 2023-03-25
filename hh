<form id="use-form" onsubmit="submitform(event)">
    <label for="name">Naveen</label>
    <input type="text" id="name" name="name" reqire>
    <label for="email">naveenreddy9378@gmail.com</label>
    <input type="email" id="email" name="email" reqired>
    <label for="phone">8790639378</label>
    <input type="tel" id="phone" name="phone" required>
    <button type=""submit"></button>
</form>
<script>
    function submitform(event)
    {
        event.preventDefault();
        cons name =document.getElementById("name").value;
        cons email =document.getElementById("email").value;
        cons phone =document.getElementById("phone").value;

        const getuserurl = 'https://example.com/api/user?email=${email}';
        fetch(getuserurl)
        ,then(response =>
        {
            if(response.ok) {
                return response.json();
            }
            else{
                throw new Error ('network response as not ok.');
            }
        })
        .then(user => {
            alert(`User ${user.name} found!`);
    })
    .catch(error => {
      const createUserUrl = 'https://example.com/api/user';
      const requestBody = { name, email, phone };

      fetch(createUserUrl, {
        method: 'POST',
        headers: { 'Content-Type': 'application/json' },
        body: JSON.stringify(requestBody),
      })
        .then(response => {
          if (response.ok) {
            return response.json();
          } else {
            throw new Error('Network response was not ok.');
          }
        })
        .then(user => {
          alert(`User ${user.name} created successfully!`);
        })
        .catch(error => {
          alert('An error occurred while creating the user.');
        });
    });
}
</script>
    }