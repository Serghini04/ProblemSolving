import './FormStyles.css';

export default function LoanForm() {
    return (<div className="flex">
        <form id='loan-form' className="form">
            <h1>Requesting a Loan</h1>
            <hr></hr>
            
            <label>Name:</label>
            <input />
            
            <label>Phone Number:</label>
            <input />
            
            <label>Phone:</label>
            <input />

            <label style={{marginTop:"30px"}}>Are you an employee?</label>
            <input type='checkbox' />
            
            <label>Salary:</label>
            <select>
                <option>less than 500$</option>
                <option>between 500$ and 2000$</option>
                <option>above 2000$</option>
            </select>

            <button id='submit-load-btn'>Submit</button>
        </form>
    </div>);
}
