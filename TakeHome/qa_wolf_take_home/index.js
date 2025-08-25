// EDIT THIS FILE TO COMPLETE ASSIGNMENT QUESTION 1
const { chromium } = require("playwright");

const iterateThroughElements = async (subtitles, arr) => {
  for (let i = 0; i < subtitles.length; i++) {
    //const title = await titles[i].textContent();
    const subtitle = await subtitles[i].getAttribute("title");
    const date= subtitle.split(" ")[0];
    arr.push( date);
  }
};
function areDatesSorted(dateArray) {
  for (let i = 0; i < dateArray.length - 1; i++) {
    // Convert to Date objects if they are strings or other formats
    const currentDate = new Date(dateArray[i]);
    const nextDate = new Date(dateArray[i + 1]);

    // Compare the dates. If current date is greater than the next, it's not sorted.
    if (currentDate.getTime() < nextDate.getTime()) {
      return false;
    }
  }
  return true; // All dates are in descending order
}

  

async function sortHackerNewsArticles() {
  // launch browser
  const browser = await chromium.launch({ headless: false });
  const context = await browser.newContext();
  const page = await context.newPage();

  // go to Hacker News
  await page.goto("https://news.ycombinator.com/newest");
  
  // get first 100 article dates
  const articleTexts = [];
  for(let i =0;i<4;i++){
    const subtitles = await page.locator('.age').all();
    await iterateThroughElements(subtitles, articleTexts);
    await page.locator('.morelink').click();
  }
  for(let i =0;i<20;i++){
    articleTexts.pop();
  }
  console.log(articleTexts);
  if(areDatesSorted(articleTexts)){
    console.log("Dates are sorted");
  } else {
    console.log("Dates are not sorted");
  }

  // close browser
  await browser.close();
  // return true if dates are sorted, false otherwise
  return areDatesSorted(articleTexts);
}

(async () => {
  await sortHackerNewsArticles();
})();


