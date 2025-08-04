// This file contains the JavaScript code that generates a random message and handles the logic for displaying it from the cloud.

const messages = [
    "Believe in yourself!",
    "Stay positive, work hard, make it happen.",
    "The best time for new beginnings is now.",
    "You are capable of amazing things.",
    "Dream big and dare to fail.",
    "Your limitation—it's only your imagination.",
    "Push yourself, because no one else is going to do it for you.",
    "Great things never come from comfort zones.",
    "Dream it. Wish it. Do it.",
    "Success doesn’t just find you. You have to go out and get it."
];

function displayRandomMessage() {
    const randomIndex = Math.floor(Math.random() * messages.length);
    const message = messages[randomIndex];
    const messageContainer = document.getElementById('message-container');
    messageContainer.innerHTML = message;
}

// Call the function to display a random message when the page loads
window.onload = displayRandomMessage();
// Add an event listener to the button to display a new random message when clicked
document.getElementById('new-message-button').addEventListener('click', displayRandomMessage);