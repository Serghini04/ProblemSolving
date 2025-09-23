// import logo from './logo.svg';
import './App.css';
import Header from './Header';
import Post from './Post';
import SideMenu from './SideMenu';


function App() {
  return (
    <div className="App">
      <Header />
      <div style={{
        display: "flex",
        justifyContent: "center"
      }}>
        {/* Posts and Side Menu */}
        <div style={{
          display:'flex',
          width: "60%"
        }}>
          {/* Posts */}
          <div style={{width:"70%"}}>
            <Post />
            <Post />
            <Post />
            <Post />
            <Post />
            <Post />
          </div>
          {/* Side Menu */}
          <div style={{width: "30%"}}>
            <SideMenu />
          </div>
        
        </div>
      </div>
      </div>
  );
}

export default App;
