const fs = require('fs');

// Read a text file and print its contents
fs.readFile('input.txt', 'utf8', (err, data) => {
    if (err) return console.error('Error reading the file:', err);
    console.log('File contents:', data);

    // Create and write to a new file
    // fs.writeFile('output.txt', 'Hello, World!', (err) => {
        // if (err) return console.error('Error writing the file:', err);
        // console.log('File created and written to!');

        // Append to the file
        // fs.appendFile('output.txt', ' How are you?', (err) => {
        //     if (err) return console.error('Error appending the file:', err);
        //     console.log('File updated!');

        //     // Read the updated file
        //     fs.readFile('output.txt', 'utf8', (err, updatedData) => {
        //         if (err) return console.error('Error reading the updated file:', err);
        //         console.log('Updated file content:', updatedData);

        //         // Delete the file
        //         fs.unlink('output.txt', (err) => {
        //             if (err) return console.error('Error deleting the file:', err);
        //             console.log('File deleted!');
        //         });
        //     });
        // });
    });
// });
 