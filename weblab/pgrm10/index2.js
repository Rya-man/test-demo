const mysql = require('mysql');

// Create a connection to MySQL
const connection = mysql.createConnection({
  host: 'localhost',
  user: 'root',
//   password: 'your_password',
  database: 'nodejstesting'
});

// Connect to MySQL
connection.connect((err) => {
  if (err) throw err;
  console.log('Connected to MySQL database');

  // Step 1: Create Database
  connection.query('CREATE DATABASE IF NOT EXISTS school', (err) => {
    if (err) throw err;
    console.log('Database "school" created or already exists');

    // Step 2: Create Table
    connection.query('CREATE TABLE IF NOT EXISTS students (id INT AUTO_INCREMENT PRIMARY KEY, name VARCHAR(255), age INT)', (err) => {
      if (err) throw err;
      console.log('Table "students" created or already exists');

      // Step 3: Insert Data
      const student = { name: 'John Doe', age: 20 };
      connection.query('INSERT INTO students SET ?', student, (err, result) => {
        if (err) throw err;
        console.log('Inserted a new student with ID:', result.insertId);

        // Step 4: Select Data
        connection.query('SELECT * FROM students', (err, rows) => {
          if (err) throw err;
          console.log('Selected all students:');
          console.log(rows);

          // Step 5: Update Data
          const newName = 'Jane Smith';
          connection.query('UPDATE students SET name = ? WHERE id = ?', [newName, 1], (err) => {
            if (err) throw err;
            console.log('Updated student with ID 1');

            // Step 6: Delete Data
            connection.query('DELETE FROM students WHERE id = ?', [1], (err) => {
              if (err) throw err;
              console.log('Deleted student with ID 1');

              // Close the connection
              connection.end();
            });
          });
        });
      });
    });
  });
});
