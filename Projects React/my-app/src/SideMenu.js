import './TagButtonStyle.css'
import TagButtom  from './TagButtom';


export default function SideMenu() {
    return (
        <div style={{
            margin: "25px",
            border: "solid teal 5px"
        }}>
            <TagButtom />
            <TagButtom />
            <TagButtom />
            <TagButtom />
            <TagButtom />
            <TagButtom />
            <TagButtom />
            <TagButtom />
        </div>
    );
}